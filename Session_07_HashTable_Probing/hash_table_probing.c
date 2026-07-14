#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define TABLE_SIZE 10

// Entry statuses:
// EMPTY: Slot has never been used
// OCCUPIED: Slot currently holds an active record
// DELETED: Tombstone (previously occupied, record deleted)
typedef enum { EMPTY, OCCUPIED, DELETED } SlotStatus;

typedef struct {
    char key[50];
    int value;
    SlotStatus status;
} HashEntry;

// Flat array representing the Hash Table
HashEntry hashTable[TABLE_SIZE];

// Initialize all slots to EMPTY
void initTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i].status = EMPTY;
    }
}

// Hash Function (simple string modulo)
unsigned int hash(const char *key) {
    unsigned int hashVal = 0;
    for (int i = 0; key[i] != '\0'; i++) {
        hashVal = hashVal * 31 + key[i];
    }
    return hashVal % TABLE_SIZE;
}

// Insert key-value pair using Linear Probing
void insert(const char *key, int value) {
    unsigned int hashIndex = hash(key);
    int index = hashIndex;
    int tombstoneIndex = -1;

    // Linear Probing loop
    for (int i = 0; i < TABLE_SIZE; i++) {
        // If key already exists in an occupied slot, update value
        if (hashTable[index].status == OCCUPIED && strcmp(hashTable[index].key, key) == 0) {
            hashTable[index].value = value;
            printf("Updated: {%s: %d} at Index %d\n", key, value, index);
            return;
        }

        // Keep track of the first tombstone we encounter to write to later
        if (hashTable[index].status == DELETED && tombstoneIndex == -1) {
            tombstoneIndex = index;
        }

        // Stop probing if we find an EMPTY slot
        if (hashTable[index].status == EMPTY) {
            break;
        }

        index = (index + 1) % TABLE_SIZE; // Linear probing step
    }

    // Determine target index: reuse tombstone if available, otherwise use the empty slot
    int targetIndex = (tombstoneIndex != -1) ? tombstoneIndex : index;

    if (hashTable[targetIndex].status == OCCUPIED) {
        printf("Hash Table is Full! Cannot insert {%s: %d}.\n", key, value);
        return;
    }

    // Insert record
    strcpy(hashTable[targetIndex].key, key);
    hashTable[targetIndex].value = value;
    hashTable[targetIndex].status = OCCUPIED;
    printf("Inserted: {%s: %d} at Index %d (Start: %d)\n", key, value, targetIndex, hashIndex);
}

// Search key: continues probing past DELETED slots, stops at EMPTY
int search(const char *key) {
    unsigned int hashIndex = hash(key);
    int index = hashIndex;

    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashTable[index].status == EMPTY) {
            return -1; // Not found
        }
        
        if (hashTable[index].status == OCCUPIED && strcmp(hashTable[index].key, key) == 0) {
            return hashTable[index].value; // Found
        }

        index = (index + 1) % TABLE_SIZE;
    }
    return -1; // Table fully probed, not found
}

// Delete key: marks the slot as DELETED (tombstone)
void delete(const char *key) {
    unsigned int hashIndex = hash(key);
    int index = hashIndex;

    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashTable[index].status == EMPTY) {
            printf("Key '%s' not found. Cannot delete.\n", key);
            return;
        }

        if (hashTable[index].status == OCCUPIED && strcmp(hashTable[index].key, key) == 0) {
            hashTable[index].status = DELETED; // Place tombstone
            printf("Deleted '%s' from Index %d. Marked as DELETED (Tombstone).\n", key, index);
            return;
        }

        index = (index + 1) % TABLE_SIZE;
    }
    printf("Key '%s' not found.\n", key);
}

// Print table layout showing slot states
void printTable() {
    printf("\n--- Hash Table Probing State ---\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("Slot %d: ", i);
        if (hashTable[i].status == EMPTY) {
            printf("[ EMPTY ]\n");
        } else if (hashTable[i].status == DELETED) {
            printf("[ DELETED (Tombstone) ]\n");
        } else {
            printf("[ OCCUPIED ] %s: %d\n", hashTable[i].key, hashTable[i].value);
        }
    }
    printf("--------------------------------\n\n");
}

int main() {
    initTable();
    printf("--- Session 07: Hash Table with Linear Probing ---\n\n");

    // Let's insert some names
    insert("Andy", 90);
    insert("Budi", 85);
    
    // Force a collision by choosing keys that will likely hash close
    insert("Agnes", 92);
    insert("Clara", 88);
    printTable();

    // Verify search
    printf("Search 'Agnes': %d\n", search("Agnes"));
    printf("Search 'Clara': %d\n\n", search("Clara"));

    // Delete "Agnes"
    delete("Agnes");
    printTable();

    // Re-verify search of "Clara" (probes past deleted slot)
    printf("Search 'Clara' after deleting 'Agnes': %d (should still be found!)\n\n", search("Clara"));

    // Insert a new key (should overwrite the deleted slot)
    insert("David", 79);
    printTable();

    printf("\nPress Enter to exit...");
    getchar();
    return 0;
}
