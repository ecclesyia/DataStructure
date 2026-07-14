#include <stdio.h>
#include <stdlib.h>

// Struct definition of a Doubly Linked List Node
typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

// Global head and tail pointers for easy bidirectional operations
Node *head = NULL;
Node *tail = NULL;

// Helper function to dynamically allocate a new Doubly Linked Node
Node *createNode(int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation error!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Insert at the head: O(1)
void pushHead(int value) {
    Node *newNode = createNode(value);
    if (head == NULL) {
        head = tail = newNode;
        return;
    }
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

// Insert at the tail: O(1) (due to keeping a global tail pointer)
void pushTail(int value) {
    Node *newNode = createNode(value);
    if (tail == NULL) {
        head = tail = newNode;
        return;
    }
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}

// Insert in sorted/ascending order: O(N)
void pushMid(int value) {
    // If list is empty or value belongs at head
    if (head == NULL || head->data >= value) {
        pushHead(value);
        return;
    }
    // If value belongs at tail
    if (tail->data <= value) {
        pushTail(value);
        return;
    }

    Node *newNode = createNode(value);
    Node *curr = head;

    // Find the first node that is larger than value
    while (curr != NULL && curr->data < value) {
        curr = curr->next;
    }

    // Insert newNode before curr
    Node *prevNode = curr->prev;

    prevNode->next = newNode;
    newNode->prev = prevNode;
    newNode->next = curr;
    curr->prev = newNode;
}

// Delete from head: O(1)
void popHead() {
    if (head == NULL) return;
    Node *temp = head;
    
    if (head == tail) { // Only 1 node in list
        head = tail = NULL;
    } else {
        head = head->next;
        head->prev = NULL;
    }
    free(temp);
}

// Delete from tail: O(1)
void popTail() {
    if (tail == NULL) return;
    Node *temp = tail;

    if (head == tail) { // Only 1 node in list
        head = tail = NULL;
    } else {
        tail = tail->prev;
        tail->next = NULL;
    }
    free(temp);
}

// Delete a specific value: O(N)
void popMid(int value) {
    if (head == NULL) return;

    if (head->data == value) {
        popHead();
        return;
    }
    if (tail->data == value) {
        popTail();
        return;
    }

    Node *curr = head;
    while (curr != NULL && curr->data != value) {
        curr = curr->next;
    }

    if (curr == NULL) {
        printf("Value %d not found.\n", value);
        return;
    }

    // Unlink curr
    Node *prevNode = curr->prev;
    Node *nextNode = curr->next;

    prevNode->next = nextNode;
    nextNode->prev = prevNode;

    free(curr);
}

// Prints list elements forward from head
void printForward() {
    printf("Forward:  ");
    Node *curr = head;
    while (curr != NULL) {
        printf("[%d] <-> ", curr->data);
        curr = curr->next;
    }
    printf("NULL\n");
}

// Prints list elements backward from tail
void printBackward() {
    printf("Backward: ");
    Node *curr = tail;
    while (curr != NULL) {
        printf("[%d] <-> ", curr->data);
        curr = curr->prev;
    }
    printf("NULL\n");
}

// Free all memory on heap
void freeList() {
    Node *curr = head;
    Node *nextNode = NULL;
    while (curr != NULL) {
        nextNode = curr->next;
        free(curr);
        curr = nextNode;
    }
    head = tail = NULL;
}

int main() {
    printf("--- Session 03: Doubly Linked List Operations ---\n\n");

    // 1. Insertions
    printf("[1] Inserting nodes (pushHead, pushTail, pushMid):\n");
    pushHead(20);    // [20]
    pushHead(10);    // [10] <-> [20]
    pushTail(40);    // [10] <-> [20] <-> [40]
    pushMid(30);     // [10] <-> [20] <-> [30] <-> [40]
    pushMid(25);     // [10] <-> [20] <-> [25] <-> [30] <-> [40]
    printForward();
    printBackward();
    printf("\n");

    // 2. Deletions
    printf("[2] Deleting from head (popHead):\n");
    popHead();
    printForward(); // [20] <-> [25] <-> [30] <-> [40]
    printf("\n");

    printf("[3] Deleting from tail (popTail):\n");
    popTail();
    printForward(); // [20] <-> [25] <-> [30]
    printf("\n");

    printf("[4] Deleting value 25 (popMid):\n");
    popMid(25);
    printForward(); // [20] <-> [30]
    printf("\n");

    // 3. Cleanup
    printf("[5] Freeing entire list...\n");
    freeList();
    printForward();

    printf("\nPress Enter to exit...");
    getchar();
    return 0;
}
