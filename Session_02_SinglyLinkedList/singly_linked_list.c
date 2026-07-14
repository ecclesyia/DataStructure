#include <stdio.h>
#include <stdlib.h>

// Struct definition of a Singly Linked List Node
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Helper function to dynamically allocate a new Node on the heap
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

// Inserts a node at the head (beginning) of the list: O(1)
void pushHead(Node **head, int value) {
    Node *newNode = createNode(value);
    newNode->next = *head;
    *head = newNode;
}

// Inserts a node at the tail (end) of the list: O(N)
void pushTail(Node **head, int value) {
    Node *newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node *curr = *head;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = newNode;
}

// Inserts a node in a sorted/ascending order: O(N)
void pushMid(Node **head, int value) {
    // If list is empty or value is smaller than head, insert at head
    if (*head == NULL || (*head)->data >= value) {
        pushHead(head, value);
        return;
    }

    Node *newNode = createNode(value);
    Node *curr = *head;

    // Traverse to find the insertion point
    while (curr->next != NULL && curr->next->data < value) {
        curr = curr->next;
    }

    newNode->next = curr->next;
    curr->next = newNode;
}

// Removes the node at the head: O(1)
void popHead(Node **head) {
    if (*head == NULL) return;
    Node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

// Removes the node at the tail: O(N)
void popTail(Node **head) {
    if (*head == NULL) return;

    Node *curr = *head;
    if (curr->next == NULL) { // Only 1 node in list
        free(curr);
        *head = NULL;
        return;
    }

    // Traverse to the second to last node
    while (curr->next->next != NULL) {
        curr = curr->next;
    }

    free(curr->next);
    curr->next = NULL;
}

// Removes a node with a specific value: O(N)
void popMid(Node **head, int value) {
    if (*head == NULL) return;

    Node *curr = *head;
    // If head node contains the target value
    if (curr->data == value) {
        popHead(head);
        return;
    }

    Node *prev = NULL;
    while (curr != NULL && curr->data != value) {
        prev = curr;
        curr = curr->next;
    }

    // Value was not found in the list
    if (curr == NULL) {
        printf("Value %d not found in list.\n", value);
        return;
    }

    // Unlink the node and free it
    prev->next = curr->next;
    free(curr);
}

// Prints all nodes in the list: O(N)
void printList(Node *head) {
    Node *curr = head;
    while (curr != NULL) {
        printf("[%d] -> ", curr->data);
        curr = curr->next;
    }
    printf("NULL\n");
}

// Clears all nodes from the heap to prevent leaks: O(N)
void freeList(Node **head) {
    Node *curr = *head;
    Node *nextNode = NULL;
    while (curr != NULL) {
        nextNode = curr->next;
        free(curr);
        curr = nextNode;
    }
    *head = NULL;
}

int main() {
    Node *head = NULL;

    printf("--- Session 02: Singly Linked List Operations ---\n\n");

    // 1. Insertions
    printf("[1] Inserting nodes (pushHead, pushTail, pushMid):\n");
    pushHead(&head, 20); // [20] -> NULL
    pushHead(&head, 10); // [10] -> [20] -> NULL
    pushTail(&head, 40); // [10] -> [20] -> [40] -> NULL
    pushMid(&head, 30);  // [10] -> [20] -> [30] -> [40] -> NULL
    printList(head);     // Output should be 10 -> 20 -> 30 -> 40 -> NULL
    printf("\n");

    // 2. Deletions
    printf("[2] Deleting head (popHead):\n");
    popHead(&head);
    printList(head); // [20] -> [30] -> [40] -> NULL
    printf("\n");

    printf("[3] Deleting tail (popTail):\n");
    popTail(&head);
    printList(head); // [20] -> [30] -> NULL
    printf("\n");

    printf("[4] Inserting 15 and 35, then deleting 30 (popMid):\n");
    pushMid(&head, 15);
    pushMid(&head, 35);
    printList(head); // [15] -> [20] -> [30] -> [35] -> NULL
    popMid(&head, 30);
    printList(head); // [15] -> [20] -> [35] -> NULL
    printf("\n");

    // 3. Cleanup
    printf("[5] Freeing entire list...\n");
    freeList(&head);
    printList(head); // NULL

    printf("\nPress Enter to exit...");
    getchar();
    return 0;
}
