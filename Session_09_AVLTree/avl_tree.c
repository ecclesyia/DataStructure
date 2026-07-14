#include <stdio.h>
#include <stdlib.h>

// Struct definition of an AVL Tree Node
typedef struct Node {
    int key;
    int height;
    struct Node *left;
    struct Node *right;
} Node;

// Safe helper to get the height of a node (returns 0 if NULL)
int getHeight(Node *node) {
    if (node == NULL) return 0;
    return node->height;
}

// Utility function to get the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Helper function to allocate a new AVL node
Node *createNode(int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation error!\n");
        exit(1);
    }
    newNode->key = value;
    newNode->height = 1; // New nodes initially have a height of 1
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Get the balance factor of a node (left height - right height)
int getBalanceFactor(Node *node) {
    if (node == NULL) return 0;
    return getHeight(node->left) - getHeight(node->right);
}

// Perform a single Right Rotation (fixes LL violation):
//      y             x
//     / \           / \
//    x   T3  --->  T1  y
//   / \               / \
//  T1  T2            T2  T3
Node *rightRotate(Node *y) {
    Node *x = y->left;
    Node *T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x; // Return new root of the subtree
}

// Perform a single Left Rotation (fixes RR violation):
//    x                 y
//   / \               / \
//  T1  y     --->    x   T3
//     / \           / \
//    T2  T3        T1  T2
Node *leftRotate(Node *x) {
    Node *y = x->right;
    Node *T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y; // Return new root of the subtree
}

// Recursive self-balancing insertion: O(log N)
Node *insert(Node *node, int value) {
    // 1. Perform standard BST insertion
    if (node == NULL) {
        return createNode(value);
    }

    if (value < node->key) {
        node->left = insert(node->left, value);
    } else if (value > node->key) {
        node->right = insert(node->right, value);
    } else {
        return node; // Duplicate keys not allowed in standard BST
    }

    // 2. Update height of this ancestor node
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    // 3. Evaluate balance factor to check if it became unbalanced
    int balance = getBalanceFactor(node);

    // Left-Left (LL) Case: Right Rotate
    if (balance > 1 && value < node->left->key) {
        printf("--- Balance factor is %d (LL). Rotating Right on Node %d ---\n", balance, node->key);
        return rightRotate(node);
    }

    // Right-Right (RR) Case: Left Rotate
    if (balance < -1 && value > node->right->key) {
        printf("--- Balance factor is %d (RR). Rotating Left on Node %d ---\n", balance, node->key);
        return leftRotate(node);
    }

    // Left-Right (LR) Case: Double Rotation (Left then Right)
    if (balance > 1 && value > node->left->key) {
        printf("--- Balance factor is %d (LR). Double Rotation on Node %d ---\n", balance, node->key);
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right-Left (RL) Case: Double Rotation (Right then Left)
    if (balance < -1 && value < node->right->key) {
        printf("--- Balance factor is %d (RL). Double Rotation on Node %d ---\n", balance, node->key);
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node; // Return unchanged node pointer
}

// Traversals for visualization
void inOrder(Node *root) {
    if (root == NULL) return;
    inOrder(root->left);
    printf("%d(H:%d) ", root->key, root->height);
    inOrder(root->right);
}

void preOrder(Node *root) {
    if (root == NULL) return;
    printf("%d ", root->key);
    preOrder(root->left);
    preOrder(root->right);
}

void freeTree(Node *root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    Node *root = NULL;

    printf("--- Session 09: AVL Self-Balancing Tree ---\n\n");

    // We insert elements in a sequence that would cause a skew tree in standard BST.
    // Inserting: 10, 20, 30 (Forces RR violation -> Left Rotate on 10)
    printf("Inserting: 10, 20, 30\n");
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    printf("Pre-order: "); preOrder(root); printf("\n\n"); // Expected root: 20

    // Inserting: 40, 50 (Forces RR violation -> Left Rotate on 30)
    printf("Inserting: 40, 50\n");
    root = insert(root, 40);
    root = insert(root, 50);
    printf("Pre-order: "); preOrder(root); printf("\n\n"); // Expected root: 20, right child: 40

    // Inserting: 25 (Forces RL violation on 20 -> Right Rotate on 30, Left Rotate on 20)
    printf("Inserting: 25\n");
    root = insert(root, 25);
    printf("Pre-order: "); preOrder(root); printf("\n\n");

    printf("Final In-order Traversal showing node heights:\n");
    inOrder(root);
    printf("\n");

    freeTree(root);
    return 0;
}
