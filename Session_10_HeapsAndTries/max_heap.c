#include <stdio.h>
#include <stdlib.h>

#define MAX_CAPACITY 20

typedef struct {
    int data[MAX_CAPACITY];
    int size;
} MaxHeap;

// Initialize Heap
MaxHeap *createHeap() {
    MaxHeap *heap = (MaxHeap *)malloc(sizeof(MaxHeap));
    heap->size = 0;
    return heap;
}

// Helper to swap two values
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Bubble up to restore Max Heap property: O(log N)
void heapifyUp(MaxHeap *heap, int index) {
    if (index == 0) return;

    int parentIndex = (index - 1) / 2;
    if (heap->data[index] > heap->data[parentIndex]) {
        swap(&heap->data[index], &heap->data[parentIndex]);
        heapifyUp(heap, parentIndex); // Recurse on parent
    }
}

// Insert item: O(log N)
void insert(MaxHeap *heap, int value) {
    if (heap->size >= MAX_CAPACITY) {
        printf("Heap full!\n");
        return;
    }
    // Place at the end of the array
    heap->data[heap->size] = value;
    heap->size++;

    // Rebalance upward
    heapifyUp(heap, heap->size - 1);
    printf("Inserted %d\n", value);
}

// Sink down to restore Max Heap property: O(log N)
void heapifyDown(MaxHeap *heap, int index) {
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;
    int largest = index;

    // Check if left child is larger
    if (leftChild < heap->size && heap->data[leftChild] > heap->data[largest]) {
        largest = leftChild;
    }

    // Check if right child is larger
    if (rightChild < heap->size && heap->data[rightChild] > heap->data[largest]) {
        largest = rightChild;
    }

    // If largest is not parent, swap and continue sinking
    if (largest != index) {
        swap(&heap->data[index], &heap->data[largest]);
        heapifyDown(heap, largest);
    }
}

// Extract and return maximum element (root): O(log N)
int extractMax(MaxHeap *heap) {
    if (heap->size <= 0) {
        printf("Heap underflow!\n");
        return -1;
    }

    int maxValue = heap->data[0];

    // Swap root with the last element
    heap->data[0] = heap->data[heap->size - 1];
    heap->size--;

    // Rebalance downward from root
    heapifyDown(heap, 0);

    return maxValue;
}

// Print heap elements in array order
void printHeap(MaxHeap *heap) {
    printf("Heap Array: ");
    for (int i = 0; i < heap->size; i++) {
        printf("%d ", heap->data[i]);
    }
    printf("\n");
}

int main() {
    MaxHeap *heap = createHeap();

    printf("--- Session 10: Binary Max Heap ---\n\n");

    // Insert priorities
    insert(heap, 40);
    insert(heap, 10);
    insert(heap, 30);
    insert(heap, 50);
    insert(heap, 20);
    printHeap(heap); // Expected: 50 40 30 10 20
    printf("\n");

    // Extract maximums
    printf("Extracting Max: %d\n", extractMax(heap)); // Expected: 50
    printHeap(heap);
    printf("\n");

    printf("Extracting Max: %d\n", extractMax(heap)); // Expected: 40
    printHeap(heap);
    
    free(heap);
    
    printf("\nPress Enter to exit...");
    getchar();
    return 0;
}
