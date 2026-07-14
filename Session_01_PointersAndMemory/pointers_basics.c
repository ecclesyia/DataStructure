#include <stdio.h>

int main() {
    printf("--- Session 01: Pointers and Pointer Arithmetic ---\n\n");

    int value = 100;
    int *ptr = &value; // Pointer initialized to store the address of 'value'

    printf("[1] Basic Referencing & Dereferencing:\n");
    printf("Value of 'value': %d\n", value);
    printf("Address of 'value' (&value): %p\n", (void *)&value);
    printf("Value stored in 'ptr': %p\n", (void *)ptr);
    printf("Value pointed to by 'ptr' (*ptr): %d\n\n", *ptr);

    // Modifying the value through the pointer
    *ptr = 250;
    printf("[2] Modifying value via pointer (*ptr = 250):\n");
    printf("New value of 'value': %d\n\n", value);

    // Pointer Arithmetic
    int arr[3] = {10, 20, 30};
    int *arrPtr = arr; // points to arr[0]

    printf("[3] Pointer Arithmetic (Array Traversal):\n");
    for (int i = 0; i < 3; i++) {
        // *(arrPtr + i) gets the value at index i by shifting the address by i * sizeof(int) bytes
        printf("Index %d: Address = %p, Value = %d\n", i, (void *)(arrPtr + i), *(arrPtr + i));
    }
    
    printf("\nPress Enter to exit...");
    getchar();
    return 0;
}
