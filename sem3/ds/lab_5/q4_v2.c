#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Define a structure for the stack
struct Stack {
    int *arr;
    int top;
    unsigned int capacity;
};

// Function to create a new stack
struct Stack *createStack(unsigned int capacity) {
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->arr = (int *)malloc(stack->capacity * sizeof(int));
    return stack;
}

// Function to check if the stack is empty
bool isEmpty(struct Stack *stack) {
    return (stack->top == -1);
}

// Function to check if the stack is full
bool isFull(struct Stack *stack) {
    return (stack->top == stack->capacity - 1);
}

// Function to push an element onto the stack
void push(struct Stack *stack, int item) {
    if (isFull(stack)) {
        printf("Stack overflow\n");
        return;
    }
    stack->arr[++stack->top] = item;
}

// Function to pop an element from the stack
int pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        return -1; // You can choose any sentinel value for error
    }
    return stack->arr[stack->top--];
}

// Function to delete k elements from the array
void deleteElements(int arr[], int n, int k) {
    // Create a stack and push arr[0]
    struct Stack *s = createStack(n);
    push(s, arr[0]);

    int count = 0;

    // Traversing a loop from i = 1 to n
    for (int i = 1; i < n; i++) {
        // Condition for deleting an element
        while (!isEmpty(s) && s->arr[s->top] < arr[i] && count < k) {
            pop(s);
            count++;
        }

        push(s, arr[i]);
    }

    // Printing the result
    while (!isEmpty(s)) {
        printf("%d ", s->arr[s->top]);
        pop(s);
    }

    printf("\n");
    free(s->arr);
    free(s);
}

// Driver code
int main() {
    int n = 5, k = 2;
    int arr[] = {20, 10, 25, 30, 40};
    deleteElements(arr, n, k);
    return 0;
}
