#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Struct definition of a Binary Search Tree Node
typedef struct Node {
    int key;
    struct Node *left;
    struct Node *right;
} Node;

// Helper function to create a new tree Node
Node *createNode(int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation error!\n");
        exit(1);
    }
    newNode->key = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Recursive insertion: O(log N) average, O(N) worst-case
Node *insert(Node *root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    if (value < root->key) {
        root->left = insert(root->left, value);
    } else if (value > root->key) {
        root->right = insert(root->right, value);
    }
    // Duplicate values are ignored in standard BSTs
    return root;
}

// Search key: O(log N) average
bool search(Node *root, int target) {
    if (root == NULL) return false;
    if (root->key == target) return true;

    if (target < root->key) {
        return search(root->left, target);
    } else {
        return search(root->right, target);
    }
}

// Helper to find the maximum value in a subtree (Predecessor finder)
Node *findMax(Node *root) {
    Node *curr = root;
    while (curr != NULL && curr->right != NULL) {
        curr = curr->right;
    }
    return curr;
}

// Delete key: O(log N) average
Node *deleteNode(Node *root, int target) {
    if (root == NULL) return NULL;

    // 1. Search for the node to delete
    if (target < root->key) {
        root->left = deleteNode(root->left, target);
    } else if (target > root->key) {
        root->right = deleteNode(root->right, target);
    } else {
        // Node found! Let's handle the 3 deletion cases:

        // Case 1 & 2: 0 children or 1 child (Right only)
        if (root->left == NULL) {
            Node *temp = root->right;
            free(root);
            return temp;
        }
        // Case 2: 1 child (Left only)
        else if (root->right == NULL) {
            Node *temp = root->left;
            free(root);
            return temp;
        }

        // Case 3: 2 children
        // We find the Predecessor (max node in left subtree)
        Node *temp = findMax(root->left);
        
        // Swap value with predecessor
        root->key = temp->key;
        
        // Recursively delete the predecessor from left subtree
        root->left = deleteNode(root->left, temp->key);
    }
    return root;
}

// In-order traversal (Left -> Root -> Right): prints sorted values
void inOrder(Node *root) {
    if (root == NULL) return;
    inOrder(root->left);
    printf("%d ", root->key);
    inOrder(root->right);
}

// Pre-order traversal (Root -> Left -> Right)
void preOrder(Node *root) {
    if (root == NULL) return;
    printf("%d ", root->key);
    preOrder(root->left);
    preOrder(root->right);
}

// Post-order traversal (Left -> Right -> Root)
void postOrder(Node *root) {
    if (root == NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->key);
}

// Free all memory on heap recursively (Post-order traversal concept)
void freeTree(Node *root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    Node *root = NULL;

    printf("--- Session 08: Binary Search Tree ---\n\n");

    // Constructing a BST:
    //        50
    //       /  \
    //      30   70
    //     / \   / \
    //    20 40 60 80
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    printf("[1] Traversals:\n");
    printf("In-order (Sorted):   "); inOrder(root); printf("\n");
    printf("Pre-order:           "); preOrder(root); printf("\n");
    printf("Post-order (Delete): "); postOrder(root); printf("\n\n");

    // Search value
    printf("[2] Searching:\n");
    printf("Search 40: %s\n", search(root, 40) ? "Found" : "Not Found");
    printf("Search 99: %s\n\n", search(root, 99) ? "Found" : "Not Found");

    // Deletion
    printf("[3] Deletion:\n");
    printf("Deleting 20 (Leaf Node):\n");
    root = deleteNode(root, 20);
    printf("In-order: "); inOrder(root); printf("\n\n");

    printf("Deleting 30 (Node with two children):\n");
    root = deleteNode(root, 30);
    printf("In-order: "); inOrder(root); printf("\n\n");

    // Clean up
    freeTree(root);
    return 0;
}
