#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PLUS 0     // '+'
#define MUL 1      // '*'
#define LPAREN 2   // '('
#define RPAREN 3   // ')'
#define ID 4       // 'id'
#define DOLLAR 5   // '$' (End of input)

#define E 0
#define T 1
#define F 2

#define SHIFT 1    
#define REDUCE 2   
#define ACCEPT 3   
#define ERROR -1   

typedef struct {
    int type;
    char lexeme[10];
} Token;

typedef struct {
    int action;
    int value;
} Action;

Action action_table[12][6] = {
    { {ERROR, 0}, {ERROR, 0}, {SHIFT, 5}, {ERROR, 0}, {SHIFT, 6}, {ERROR, 0} },
    { {SHIFT, 2}, {ERROR, 0}, {ERROR, 0}, {ERROR, 0}, {ERROR, 0}, {ACCEPT, 0} },
    { {ERROR, 0}, {ERROR, 0}, {ERROR, 0}, {ERROR, 0}, {SHIFT, 6}, {ERROR, 0} },
    { {REDUCE, 1}, {SHIFT, 7}, {ERROR, 0}, {REDUCE, 1}, {ERROR, 0}, {REDUCE, 1} },
    { {REDUCE, 4}, {REDUCE, 4}, {ERROR, 0}, {REDUCE, 4}, {ERROR, 0}, {REDUCE, 4} },
    { {ERROR, 0}, {ERROR, 0}, {SHIFT, 5}, {ERROR, 0}, {SHIFT, 6}, {ERROR, 0} },
    { {REDUCE, 6}, {REDUCE, 6}, {ERROR, 0}, {REDUCE, 6}, {ERROR, 0}, {REDUCE, 6} },
    { {ERROR, 0}, {ERROR, 0}, {SHIFT, 5}, {ERROR, 0}, {SHIFT, 6}, {ERROR, 0} },
    { {REDUCE, 3}, {REDUCE, 3}, {ERROR, 0}, {REDUCE, 3}, {ERROR, 0}, {REDUCE, 3} },
    { {SHIFT, 2}, {ERROR, 0}, {ERROR, 0}, {SHIFT, 11}, {ERROR, 0}, {ERROR, 0} },
    { {REDUCE, 2}, {SHIFT, 7}, {ERROR, 0}, {REDUCE, 2}, {ERROR, 0}, {REDUCE, 2} },
    { {REDUCE, 5}, {REDUCE, 5}, {ERROR, 0}, {REDUCE, 5}, {ERROR, 0}, {REDUCE, 5} },
};

int goto_table[12][3] = {
    { 1, 10, 4 },
    { -1, -1, -1 },
    { -1, 3, 4 },
    { -1, -1, -1 },
    { -1, -1, -1 },
    { 9, 10, 4 },
    { -1, -1, -1 },
    { -1, -1, 8 },
    { -1, -1, -1 },
    { -1, -1, -1 },
    { -1, -1, -1 },
    { -1, -1, -1 },
};

#define STACK_SIZE 100
int stack[STACK_SIZE];
int top = -1;

void push(int state) {
    stack[++top] = state;
}

int pop() {
    return stack[top--];
}

int peek() {
    return stack[top];
}

void print_stack() {
    for (int i = 0; i <= top; i++) {
        printf("%d ", stack[i]);
    }
}

void parse(Token tokens[], int n) {
    push(0);
    int i = 0;

    printf("\n%-20s %s\n", "Stack", "Action");
    printf("---------------------------------\n");

    while (1) {
        int state = peek();
        int token = tokens[i].type;

        print_stack();
        printf("  ");

        Action action = action_table[state][token];

        if (action.action == SHIFT) {
            printf("Shift %d\n", action.value);
            push(action.value);
            i++;
        } else if (action.action == REDUCE) {
            printf("Reduce by rule %d\n", action.value);
            int rule = action.value;
            int pop_count;
            int non_terminal;

            switch (rule) {
                case 1: pop_count = 3; non_terminal = E; break;
                case 2: pop_count = 1; non_terminal = E; break;
                case 3: pop_count = 3; non_terminal = T; break;
                case 4: pop_count = 1; non_terminal = T; break;
                case 5: pop_count = 3; non_terminal = F; break;
                case 6: pop_count = 1; non_terminal = F; break;
                default: printf("Invalid reduction rule\n"); return;
            }

            while (pop_count--) pop();

            int next_state = goto_table[peek()][non_terminal];
            if (next_state == -1) {
                printf("GOTO error\n");
                return;
            }
            push(next_state);
        } else if (action.action == ACCEPT) {
            printf("Parsing successful!\n");
            return;
        } else {
            printf("Syntax error at token %s\n", tokens[i].lexeme);
            return;
        }
    }
}

int get_token_type(char *lexeme) {
    if (strcmp(lexeme, "+") == 0) return PLUS;
    if (strcmp(lexeme, "*") == 0) return MUL;
    if (strcmp(lexeme, "(") == 0) return LPAREN;
    if (strcmp(lexeme, ")") == 0) return RPAREN;
    if (strcmp(lexeme, "id") == 0) return ID;
    return -1;
}

int main() {
    char input[100];
    printf("Enter expression (use 'id' for variables and '$' for end of input):\n");
    fgets(input, sizeof(input), stdin);

    Token tokens[50];
    int token_count = 0;

    char *token = strtok(input, " \n");
    while (token) {
        if (strcmp(token, "$") == 0) {
            tokens[token_count++] = (Token){DOLLAR, "$"};
            break;
        }

        int type = get_token_type(token);
        if (type == -1) {
            printf("Invalid token: %s\n", token);
            return 1;
        }
        strcpy(tokens[token_count].lexeme, token);
        tokens[token_count].type = type;
        token_count++;

        token = strtok(NULL, " \n");
    }

    parse(tokens, token_count);
    return 0;
}
