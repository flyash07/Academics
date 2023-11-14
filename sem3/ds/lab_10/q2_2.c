#include <stdio.h>
#include <stdlib.h>

// Define a circular doubly linked list node structure
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

// Create a new node with the given data
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = newNode->prev = NULL;
    return newNode;
}

// Insert a node at the end of the circular doubly linked list
void insertEnd(Node* header, int data) {
    Node* newNode = createNode(data);
    newNode->next = header;
    newNode->prev = header->prev;
    header->prev->next = newNode;
    header->prev = newNode;
}

// Add two circular doubly linked lists representing long integers
Node* addLongIntegers(Node* num1, Node* num2) {
    Node* resultHeader = createNode(0); // Create a header node for the result
    Node* current1 = num1->prev;
    Node* current2 = num2->prev;
    int carry = 0;

    while (current1 != num1 && current2 != num2) {
        int sum = current1->data + current2->data + carry;
        carry = sum / 10;
        insertEnd(resultHeader, sum % 10);
        current1 = current1->prev;
        current2 = current2->prev;
    }

    while (current1 != num1) {
        int sum = current1->data + carry;
        carry = sum / 10;
        insertEnd(resultHeader, sum % 10);
        current1 = current1->prev;
    }

    while (current2 != num2) {
        int sum = current2->data + carry;
        carry = sum / 10;
        insertEnd(resultHeader, sum % 10);
        current2 = current2->prev;
    }

    if (carry > 0) {
        insertEnd(resultHeader, carry);
    }

    return resultHeader;
}

// Display the circular doubly linked list
void displayList(Node* header) {
    Node* current = header->next;
    while (current != header) {
        printf("%d", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Node* num1Header = createNode(0); // Create header nodes for both numbers
    Node* num2Header = createNode(0);

    // Input numbers (as strings, e.g., "12345" is represented as 5 -> 4 -> 3 -> 2 -> 1)
    char num1Str[] = "12345";
    char num2Str[] = "6789";

    for (int i = 0; num1Str[i] != '\0'; i++) {
        insertEnd(num1Header, num1Str[i] - '0');
    }

    for (int i = 0; num2Str[i] != '\0'; i++) {
        insertEnd(num2Header, num2Str[i] - '0');
    }

    // Add the two numbers
    Node* result = addLongIntegers(num1Header, num2Header);

    // Display the result
    displayList(result);

    // Free memory
    free(num1Header);
    free(num2Header);
    free(result);

    return 0;
}
