#include <stdio.h>
#include <stdlib.h>

// Struct definition of a Singly Circular Linked List Node
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Helper function to dynamically allocate a Node
Node *createNode(int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation error!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Insert at the head: O(1) if keeping a pointer to tail, otherwise O(N)
void pushHead(Node **head, int value) {
    Node *newNode = createNode(value);

    // If list is empty, point newNode to itself
    if (*head == NULL) {
        newNode->next = newNode;
        *head = newNode;
        return;
    }

    // Traverse to the tail node to update its next reference
    Node *tailNode = *head;
    while (tailNode->next != *head) {
        tailNode = tailNode->next;
    }

    newNode->next = *head;
    tailNode->next = newNode;
    *head = newNode; // update head pointer
}

// Insert at the tail: O(N) to find the tail
void pushTail(Node **head, int value) {
    Node *newNode = createNode(value);

    if (*head == NULL) {
        newNode->next = newNode;
        *head = newNode;
        return;
    }

    // Find tail node
    Node *tailNode = *head;
    while (tailNode->next != *head) {
        tailNode = tailNode->next;
    }

    tailNode->next = newNode;
    newNode->next = *head;
}

// Delete head node: O(N)
void popHead(Node **head) {
    if (*head == NULL) return;

    Node *temp = *head;

    // Only 1 node in the circular list
    if (temp->next == *head) {
        free(temp);
        *head = NULL;
        return;
    }

    // Find the tail node to update its next pointer
    Node *tailNode = *head;
    while (tailNode->next != *head) {
        tailNode = tailNode->next;
    }

    *head = (*head)->next; // Move head to next node
    tailNode->next = *head; // Tail points to new head
    free(temp);
}

// Prints the circular list (using do-while to ensure we visit all nodes)
void printList(Node *head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node *curr = head;
    do {
        printf("[%d] -> ", curr->data);
        curr = curr->next;
    } while (curr != head);
    printf("(Back to Head: [%d])\n", head->data);
}

// Clears all nodes from heap without infinite loops
void freeList(Node **head) {
    if (*head == NULL) return;

    Node *curr = *head;
    Node *nextNode = NULL;
    Node *tailNode = *head;

    // First find the tail to unlink the circle (make it linear)
    while (tailNode->next != *head) {
        tailNode = tailNode->next;
    }
    tailNode->next = NULL; // Circle broken, now it is a standard linear list!

    // Free nodes linearly
    while (curr != NULL) {
        nextNode = curr->next;
        free(curr);
        curr = nextNode;
    }
    *head = NULL;
}

int main() {
    Node *head = NULL;

    printf("--- Session 04: Circular Linked List Operations ---\n\n");

    // 1. Insertions
    printf("[1] Inserting nodes (pushHead, pushTail):\n");
    pushHead(&head, 20); // [20] -> back to [20]
    pushHead(&head, 10); // [10] -> [20] -> back to [10]
    pushTail(&head, 30); // [10] -> [20] -> [30] -> back to [10]
    pushTail(&head, 40); // [10] -> [20] -> [30] -> [40] -> back to [10]
    printList(head);
    printf("\n");

    // 2. Deletion
    printf("[2] Deleting head (popHead):\n");
    popHead(&head);
    printList(head); // [20] -> [30] -> [40] -> back to [20]
    printf("\n");

    // 3. Cleanup
    printf("[3] Freeing entire list (breaking circular loop first)...\n");
    freeList(&head);
    printList(head);

    printf("\nPress Enter to exit...");
    getchar();
    return 0;
}
