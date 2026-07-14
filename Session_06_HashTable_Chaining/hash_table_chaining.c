#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 7

// Hash Table Node structure (chain node)
typedef struct Node {
    char key[50];
    int value;
    struct Node *next;
} Node;

// Hash Table array of bucket pointers
Node *hashTable[TABLE_SIZE] = {NULL};

// A simple string hash function (Polynomial rolling hash concept / DJB2-like)
unsigned int hash(const char *key) {
    unsigned long int hashVal = 5381;
    int i = 0;
    while (key[i] != '\0') {
        hashVal = ((hashVal << 5) + hashVal) + key[i]; // hashVal * 33 + key[i]
        i++;
    }
    return hashVal % TABLE_SIZE;
}

// Insert key-value pair: O(1) average
void insert(const char *key, int value) {
    unsigned int index = hash(key);

    // Check if key already exists, update value if found
    Node *curr = hashTable[index];
    while (curr != NULL) {
        if (strcmp(curr->key, key) == 0) {
            curr->value = value; // Update value
            return;
        }
        curr = curr->next;
    }

    // Key doesn't exist, create a new Node and push it at the head of the chain
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation error!\n");
        exit(1);
    }
    strcpy(newNode->key, key);
    newNode->value = value;
    newNode->next = hashTable[index];
    hashTable[index] = newNode;
    printf("Inserted: {%s: %d} at Index %d\n", key, value, index);
}

// Search value by key: O(1) average, O(N) worst-case
int search(const char *key) {
    unsigned int index = hash(key);
    
    Node *curr = hashTable[index];
    while (curr != NULL) {
        if (strcmp(curr->key, key) == 0) {
            return curr->value; // Key found
        }
        curr = curr->next;
    }
    return -1; // Key not found
}

// Delete key-value pair: O(1) average
void delete(const char *key) {
    unsigned int index = hash(key);
    
    Node *curr = hashTable[index];
    Node *prev = NULL;

    while (curr != NULL && strcmp(curr->key, key) != 0) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == NULL) {
        printf("Key '%s' not found. Deletion failed.\n", key);
        return;
    }

    // Unlink and free
    if (prev == NULL) {
        // Deleting the head of the chain
        hashTable[index] = curr->next;
    } else {
        prev->next = curr->next;
    }

    free(curr);
    printf("Deleted key '%s' from Index %d\n", key, index);
}

// Print the hash table slots
void printTable() {
    printf("\n--- Hash Table State ---\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("Slot %d: ", i);
        Node *curr = hashTable[i];
        if (curr == NULL) {
            printf("NULL\n");
            continue;
        }
        while (curr != NULL) {
            printf("{%s: %d} -> ", curr->key, curr->value);
            curr = curr->next;
        }
        printf("NULL\n");
    }
    printf("------------------------\n\n");
}

// Free all memory to avoid leaks
void freeTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        Node *curr = hashTable[i];
        while (curr != NULL) {
            Node *temp = curr;
            curr = curr->next;
            free(temp);
        }
        hashTable[i] = NULL;
    }
}

int main() {
    printf("--- Session 06: Hash Table with Chaining ---\n\n");

    // Insert elements
    insert("Budi", 95);
    insert("Siti", 88);
    insert("Clara", 74);
    insert("Andi", 85); // Will cause collision if hash matches
    insert("Dewi", 92);
    
    printTable();

    // Search keys
    printf("Search 'Siti': %d\n", search("Siti"));
    printf("Search 'Tono' (Not Exists): %d\n\n", search("Tono"));

    // Delete a key
    delete("Clara");
    printTable();

    // Clean up
    freeTable();
    return 0;
}
