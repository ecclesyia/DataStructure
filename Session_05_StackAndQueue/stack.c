#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Node structure of the stack (implemented as a Singly Linked List)
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Global stack top pointer
Node *top = NULL;

// Helper function to create a new Node on the heap
Node *createNode(int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Heap memory full!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Check if the stack is empty: O(1)
bool isEmpty() {
    return top == NULL;
}

// Push an element onto the stack: O(1)
void push(int value) {
    Node *newNode = createNode(value);
    newNode->next = top;
    top = newNode;
    printf("Pushed: %d\n", value);
}

// Pop the top element off the stack: O(1)
void pop() {
    if (isEmpty()) {
        printf("Stack Underflow! Cannot pop.\n");
        return;
    }
    Node *temp = top;
    int poppedValue = temp->data;
    top = top->next;
    free(temp);
    printf("Popped: %d\n", poppedValue);
}

// Peek at the top element without removing it: O(1)
int peek() {
    if (isEmpty()) {
        printf("Stack is empty!\n");
        return -1;
    }
    return top->data;
}

// Print all elements currently in the stack (top to bottom)
void printStack() {
    if (isEmpty()) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack (Top -> Bottom): ");
    Node *curr = top;
    while (curr != NULL) {
        printf("[%d] -> ", curr->data);
        curr = curr->next;
    }
    printf("NULL\n");
}

// Free all allocated stack memory
void clearStack() {
    while (!isEmpty()) {
        pop();
    }
}

int main() {
    printf("--- Session 05: Dynamic Stack (LIFO) ---\n\n");

    push(10);
    push(20);
    push(30);
    printStack(); // [30] -> [20] -> [10] -> NULL

    printf("Top element (peek): %d\n\n", peek());

    pop();
    printStack(); // [20] -> [10] -> NULL

    pop();
    pop();
    printStack(); // Stack is empty

    pop(); // Try to pop empty stack

    printf("\nPress Enter to exit...");
    getchar();
    return 0;
}
