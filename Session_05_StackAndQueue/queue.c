#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Node structure of the Queue
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Global pointers to keep track of both endpoints of the Queue
Node *front = NULL;
Node *rear = NULL;

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

// Check if Queue is empty: O(1)
bool isEmpty() {
    return front == NULL;
}

// Add an element to the rear of the Queue: O(1)
void enqueue(int value) {
    Node *newNode = createNode(value);
    
    // If queue is empty, both front and rear point to the new node
    if (isEmpty()) {
        front = rear = newNode;
        printf("Enqueued: %d\n", value);
        return;
    }

    rear->next = newNode;
    rear = newNode;
    printf("Enqueued: %d\n", value);
}

// Remove an element from the front of the Queue: O(1)
void dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow! Cannot dequeue.\n");
        return;
    }

    Node *temp = front;
    int dequeuedValue = temp->data;

    front = front->next;

    // If the queue becomes empty after dequeuing, set rear to NULL as well
    if (front == NULL) {
        rear = NULL;
    }

    free(temp);
    printf("Dequeued: %d\n", dequeuedValue);
}

// Peek at the front element: O(1)
int peekFront() {
    if (isEmpty()) {
        printf("Queue is empty!\n");
        return -1;
    }
    return front->data;
}

// Print elements in the Queue (front to rear)
void printQueue() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue (Front -> Rear): ");
    Node *curr = front;
    while (curr != NULL) {
        printf("[%d] -> ", curr->data);
        curr = curr->next;
    }
    printf("NULL\n");
}

int main() {
    printf("--- Session 05: Dynamic Queue (FIFO) ---\n\n");

    enqueue(10);
    enqueue(20);
    enqueue(30);
    printQueue(); // [10] -> [20] -> [30] -> NULL

    printf("Front element (peek): %d\n\n", peekFront());

    dequeue();
    printQueue(); // [20] -> [30] -> NULL

    dequeue();
    dequeue();
    printQueue(); // Queue is empty

    dequeue(); // Try to dequeue empty queue

    printf("\nPress Enter to exit...");
    getchar();
    return 0;
}
