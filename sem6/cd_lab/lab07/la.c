#include <stdio.h>
#include <string.h>
#include "remove.h"
#include "token.h"
#include "symbol_table.h"


int index = 0;



void printallfunctions(token tt[], int tp) {
    
    for (int i = 0; i < tp - 2; i++) { 
        if (strcmp(tt[i].type, "keyword") == 0) { 
       
            if (strcmp(tt[i + 1].type, "identifier") == 0) { 


                if (strcmp(tt[i + 2].token_name, "(") == 0) {
                    printf("Function: %s\n", tt[i + 1].token_name);
                    
                    int j = i;
                    while (j < tp && strcmp(tt[j].token_name, ")") != 0) {
                        printf("%s ", tt[j].token_name);
                        j++;
                    }
                    
                    if (j < tp) {
                        printf(" %s", tt[j].token_name); 
                    }
                    
                    printf("\n");
                    
                    i = j; 
                }
            }
        }
    }
}


// void symbol_table(token tt[], int tp) {
//     int braces = 0;
//     int in_function = 0; // Flag to track if we are inside a function
//     SymbolTable *current_table = NULL;

//     for (int i = 0; i < tp; i++) {
//         if (strcmp(tt[i].type, "keyword") == 0) {
//             if (i + 1 < tp && strcmp(tt[i + 1].type, "identifier") == 0) {
//                 if (i + 2 < tp && strcmp(tt[i + 2].token_name, "(") == 0) {
//                     // Found a function definition
//                     current_table = &code[codecounter++];
//                     strcpy(current_table->name, tt[i + 1].token_name);
//                     in_function = 1;
//                     braces = 0; // Reset braces count for this function
//                     i += 3; // Move past function name and '('

//                     // **Function argument detection**
//                     while (i < tp && strcmp(tt[i].token_name, ")") != 0) {
//                         if (strcmp(tt[i].type, "keyword") == 0 && i + 1 < tp && strcmp(tt[i + 1].type, "identifier") == 0) {
//                             char *arg_type = tt[i].token_name;
//                             char *arg_name = tt[i + 1].token_name;
//                             int arg_size = get_type_size(arg_type);
//                             insert_symbol(current_table, arg_name, arg_type, arg_size);
//                             i += 2; // Move past argument type and name
//                         }
//                         if (i < tp && strcmp(tt[i].token_name, ",") == 0) {
//                             i++; // Move past comma to next argument
//                         }
//                     }
//                 }
//             }
//         }

//         if (in_function) {
//             if (strcmp(tt[i].token_name, "{") == 0) {
//                 braces++;
//             } else if (strcmp(tt[i].token_name, "}") == 0) {
//                 braces--;
//                 if (braces == 0) {
//                     in_function = 0; // Function scope ended
//                     current_table = NULL;
//                 }
//             } else if (current_table != NULL) {
//                 // Variable declaration inside function
//                 if (strcmp(tt[i].type, "keyword") == 0) {
//                     char *var_type = tt[i].token_name;
//                     int var_size = get_type_size(var_type);
//                     i++; // Move to the first identifier

//                     if (strcmp(tt[i].type, "identifier") == 0) {
//                         while (i < tp ) {
//                             char *var_name = tt[i].token_name;
//                             int final_size = var_size; // Default size
    
//                             if (i + 1 < tp && strcmp(tt[i + 1].token_name, "[") == 0) {
//                                 if (i + 2 < tp && strcmp(tt[i + 2].type, "number") == 0) {
//                                     final_size *= atoi(tt[i + 2].token_name); // Multiply size by array length
//                                     i += 4; // Move past '[', number, and ']'
//                                 } else {
//                                     i += 2; // Move past '[' if size is missing
//                                 }
//                             } else {
//                                 i++; // Move past normal identifier
//                             }
    
//                             insert_symbol(current_table, var_name, var_type, final_size);
                            
//                             // **Handle Multiple Declarations**
//                             if (i < tp && strcmp(tt[i].token_name, ",") == 0) {
//                                 i++; // Move to next identifier
//                             } else {
//                                 break; // No more variables in this declaration
//                             }
//                         }
//                     }
                   
//                 }
//             }
//         }
//     }

//     // Print all function symbol tables
//     printf("\nFunction Symbol Tables:\n");
//     for (int j = 0; j < codecounter; j++) {
//         printf("\nSymbol Table for function: %s\n", code[j].name);
//         printf("SN\tLexeme\tType\tSize\n");
//         for (int i = 0; i < TABLE_SIZE; i++) {
//             if (code[j].table[i].is_occupied) {
//                 printf("%d\t%s\t%s\t%d\n", 
//                        code[j].table[i].serial_number, 
//                        code[j].table[i].lex_name, 
//                        code[j].table[i].type, 
//                        code[j].table[i].size);
//             }
//         }
//     }
// }


token tt[100];  
int tp = 0; 


int la() {
    FILE *fr, *fw1, *fw2;

    fr = fopen("input.c", "r");
    fw1 = fopen("op1.txt", "w");
    removepdirective(fr, fw1);
    fclose(fr);
    fclose(fw1);

    fw1 = fopen("op1.txt", "r");
    fw2 = fopen("op2.txt", "w");
    removecomments(fw1, fw2);
    fclose(fw1);
    fclose(fw2);

    fw1 = fopen("op2.txt", "r");
    while (getnexttoken1(fw1, tt, &tp) != -1);
    fclose(fw1);


    printallfunctions(tt,tp);
    symbol_table(tt, tp);

    // for (int i = 0; i < tp; i++) {
    //     token current_token = tt[i];

    //     if ((strcmp(tt[i ].type, "keyword") == 0 ) )
        
    //     if ((strcmp(tt[i + 1].type, "identifier") == 0) && (strcmp(tt[i +1].token_name, "main") != 0 )) { 
    //         char *var_name = tt[i + 1].token_name;
    //         char *  var_type = tt[i].token_name;
    //         int var_size = get_type_size(var_type);

    //         if (i + 2 < tp && strcmp(tt[i + 2].token_name, "[") == 0) {
    //             if (i + 3 < tp && strcmp(tt[i + 3].type, "number") == 0) {
    //                 var_size *= atoi(tt[i + 3].token_name); // Multiply size by array length
    //                 i += 3; // Move past '[' and array size
    //             }
    //         }

    //         insert_symbol(&main_symbol_table, var_name, var_type, var_size);

    //         i += 1;
    //     }
    // }

    // printf("\nSymbol Table for main():\n");
    // printf("SN\tlex\ttype\tsize\n");
    // for (int i = 0; i < TABLE_SIZE; i++) {
    //     if (main_symbol_table.table[i].is_occupied) {
    //         printf("%d\t%s\t%s\t%d\n", 
    //                main_symbol_table.table[i].serial_number, 
    //                main_symbol_table.table[i].lex_name, 
    //                main_symbol_table.table[i].type, 
    //                main_symbol_table.table[i].size);
    //     }
    // }


    return 1;
}

int getnexttoken(token * t) {
    if (index < tp) {
        *t = tt[index++];
        return 1;
    } else return 0;
}
