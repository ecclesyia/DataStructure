#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define ALPHABET_SIZE 26

// Struct definition of a Trie Node
typedef struct TrieNode {
    struct TrieNode *children[ALPHABET_SIZE];
    bool isEndOfWord;
} TrieNode;

// Helper to create a new Trie Node initialized to NULL/false
TrieNode *createNode() {
    TrieNode *newNode = (TrieNode *)malloc(sizeof(TrieNode));
    if (newNode == NULL) {
        printf("Memory allocation error!\n");
        exit(1);
    }
    newNode->isEndOfWord = false;
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        newNode->children[i] = NULL;
    }
    return newNode;
}

// Insert word: O(L) where L is word length
void insert(TrieNode *root, const char *word) {
    TrieNode *curr = root;
    for (int i = 0; word[i] != '\0'; i++) {
        int index = word[i] - 'a'; // convert character to index 0-25
        
        if (index < 0 || index >= ALPHABET_SIZE) {
            printf("Invalid character '%c' in word. Only lowercase a-z allowed.\n", word[i]);
            return;
        }

        if (curr->children[index] == NULL) {
            curr->children[index] = createNode();
        }
        curr = curr->children[index];
    }
    curr->isEndOfWord = true;
    printf("Inserted word: '%s'\n", word);
}

// Search word: O(L)
bool search(TrieNode *root, const char *word) {
    TrieNode *curr = root;
    for (int i = 0; word[i] != '\0'; i++) {
        int index = word[i] - 'a';
        if (index < 0 || index >= ALPHABET_SIZE || curr->children[index] == NULL) {
            return false;
        }
        curr = curr->children[index];
    }
    return curr != NULL && curr->isEndOfWord;
}

// Check if any word starts with prefix: O(L)
bool startsWith(TrieNode *root, const char *prefix) {
    TrieNode *curr = root;
    for (int i = 0; prefix[i] != '\0'; i++) {
        int index = prefix[i] - 'a';
        if (index < 0 || index >= ALPHABET_SIZE || curr->children[index] == NULL) {
            return false;
        }
        curr = curr->children[index];
    }
    return curr != NULL;
}

// Free all memory recursively
void freeTrie(TrieNode *root) {
    if (root == NULL) return;
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        freeTrie(root->children[i]);
    }
    free(root);
}

int main() {
    TrieNode *root = createNode();

    printf("--- Session 10: Trie (Prefix Tree) ---\n\n");

    // Insert strings
    insert(root, "apple");
    insert(root, "app");
    insert(root, "apricot");
    insert(root, "banana");
    printf("\n");

    // Search tests
    printf("Search 'apple': %s\n", search(root, "apple") ? "Found" : "Not Found");
    printf("Search 'app':   %s\n", search(root, "app") ? "Found" : "Not Found");
    printf("Search 'appl':  %s\n", search(root, "appl") ? "Found" : "Not Found");
    printf("Search 'orange':%s\n\n", search(root, "orange") ? "Found" : "Not Found");

    // Prefix checking
    printf("StartsWith 'ap':   %s\n", startsWith(root, "ap") ? "Yes" : "No");
    printf("StartsWith 'ban':  %s\n", startsWith(root, "ban") ? "Yes" : "No");
    printf("StartsWith 'ora':  %s\n", startsWith(root, "ora") ? "Yes" : "No");

    // Clean up
    freeTrie(root);
    
    printf("\nPress Enter to exit...");
    getchar();
    return 0;
}
