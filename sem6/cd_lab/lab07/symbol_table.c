#include "symbol_table.h"

SymbolTable main_symbol_table;
SymbolTable code[100];
int codecounter = 0;

int search_symbol(SymbolTable *st, const char *lex_name) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (st->table[i].is_occupied && strcmp(st->table[i].lex_name, lex_name) == 0) {
            return i;
        }
    }
    return -1;
}

int insert_symbol(SymbolTable *st, const char *lex_name, const char *type, int size) {
    if (search_symbol(st, lex_name) != -1) {
        return -2;
    }
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (!st->table[i].is_occupied) {
            st->table[i].serial_number = i + 1;
            strcpy(st->table[i].lex_name, lex_name);
            strcpy(st->table[i].type, type);
            st->table[i].size = size;
            st->table[i].is_occupied = 1;
            return 0;
        }
    }
    return -1;
}

int get_type_size(const char *type) {
    if (strcmp(type, "int") == 0) return sizeof(int);
    if (strcmp(type, "float") == 0) return sizeof(float);
    if (strcmp(type, "double") == 0) return sizeof(double);
    if (strcmp(type, "char") == 0) return sizeof(char);
    return -1;  
}

void symbol_table(token tt[], int tp) {
    int braces = 0;
    int in_function = 0; // Flag to track if we are inside a function
    SymbolTable *current_table = NULL;

    for (int i = 0; i < tp; i++) {
        if (strcmp(tt[i].type, "keyword") == 0) {
            if (i + 1 < tp && strcmp(tt[i + 1].type, "identifier") == 0) {
                if (i + 2 < tp && strcmp(tt[i + 2].token_name, "(") == 0) {
                    // Found a function definition
                    current_table = &code[codecounter++];
                    strcpy(current_table->name, tt[i + 1].token_name);
                    in_function = 1;
                    braces = 0; // Reset braces count for this function
                    i += 3; // Move past function name and '('

                    // **Function argument detection**
                    while (i < tp && strcmp(tt[i].token_name, ")") != 0) {
                        if (strcmp(tt[i].type, "keyword") == 0 && i + 1 < tp && strcmp(tt[i + 1].type, "identifier") == 0) {
                            char *arg_type = tt[i].token_name;
                            char *arg_name = tt[i + 1].token_name;
                            int arg_size = get_type_size(arg_type);
                            insert_symbol(current_table, arg_name, arg_type, arg_size);
                            i += 2; // Move past argument type and name
                        }
                        if (i < tp && strcmp(tt[i].token_name, ",") == 0) {
                            i++; // Move past comma to next argument
                        }
                    }
                }
            }
        } else if (i  < tp && strcmp(tt[i ].type, "identifier") == 0) {
            if (i + 1 < tp && strcmp(tt[i + 1].token_name, "(") == 0) {
                // Found a function definition
                current_table = &code[codecounter++];
                strcpy(current_table->name, tt[i].token_name);
                in_function = 1;
                braces = 0; // Reset braces count for this function
                i += 2; // Move past function name and '('

                // **Function argument detection**
                while (i < tp && strcmp(tt[i].token_name, ")") != 0) {
                    if (strcmp(tt[i].type, "keyword") == 0 && i + 1 < tp && strcmp(tt[i + 1].type, "identifier") == 0) {
                        char *arg_type = tt[i].token_name;
                        char *arg_name = tt[i + 1].token_name;
                        int arg_size = get_type_size(arg_type);
                        insert_symbol(current_table, arg_name, arg_type, arg_size);
                        i += 2; // Move past argument type and name
                    }
                    if (i < tp && strcmp(tt[i].token_name, ",") == 0) {
                        i++; // Move past comma to next argument
                    }
                }
            }
        }

        if (in_function) {
            if (strcmp(tt[i].token_name, "{") == 0) {
                braces++;
            } else if (strcmp(tt[i].token_name, "}") == 0) {
                braces--;
                if (braces == 0) {
                    in_function = 0; // Function scope ended
                    current_table = NULL;
                }
            } else if (current_table != NULL) {
                // Variable declaration inside function
                if (strcmp(tt[i].type, "keyword") == 0) {
                    char *var_type = tt[i].token_name;
                    int var_size = get_type_size(var_type);
                    i++; // Move to the first identifier

                    if (strcmp(tt[i].type, "identifier") == 0) {
                        while (i < tp ) {
                            char *var_name = tt[i].token_name;
                            int final_size = var_size; // Default size
    
                            if (i + 1 < tp && strcmp(tt[i + 1].token_name, "[") == 0) {
                                if (i + 2 < tp && strcmp(tt[i + 2].type, "number") == 0) {
                                    final_size *= atoi(tt[i + 2].token_name); // Multiply size by array length
                                    i += 4; // Move past '[', number, and ']'
                                } else {
                                    i += 2; // Move past '[' if size is missing
                                }
                            } else {
                                i++; // Move past normal identifier
                            }
    
                            insert_symbol(current_table, var_name, var_type, final_size);
                            
                            // **Handle Multiple Declarations**
                            if (i < tp && strcmp(tt[i].token_name, ",") == 0) {
                                i++; // Move to next identifier
                            } else {
                                break; // No more variables in this declaration
                            }
                        }
                    }
                   
                }
            }
        }
    }

    // Print all function symbol tables
    printf("\nFunction Symbol Tables:\n");
    for (int j = 0; j < codecounter; j++) {
        printf("\nSymbol Table for function: %s\n", code[j].name);
        printf("SN\tLexeme\tType\tSize\n");
        for (int i = 0; i < TABLE_SIZE; i++) {
            if (code[j].table[i].is_occupied) {
                printf("%d\t%s\t%s\t%d\n", 
                       code[j].table[i].serial_number, 
                       code[j].table[i].lex_name, 
                       code[j].table[i].type, 
                       code[j].table[i].size);
            }
        }
    }
}

void synctables(SymbolTable * st) {
    st = code;
    return;
}