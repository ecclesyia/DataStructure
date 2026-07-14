#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *parent;
    int *rank;
    int size;
} DisjointSet;

// Initialize Disjoint Set with N elements
DisjointSet *createSet(int N) {
    DisjointSet *set = (DisjointSet *)malloc(sizeof(DisjointSet));
    set->size = N;
    set->parent = (int *)malloc(N * sizeof(int));
    set->rank = (int *)malloc(N * sizeof(int));

    for (int i = 0; i < N; i++) {
        set->parent[i] = i; // Each node is its own parent initially
        set->rank[i] = 0;   // Height/rank starts at 0
    }
    return set;
}

// Find representative of element i: O(alpha(N)) ~ O(1) average due to Path Compression
int find(DisjointSet *set, int i) {
    // If i is the root, return i
    if (set->parent[i] == i) {
        return i;
    }

    // Path Compression: directly link node to root, flattening the tree structure!
    set->parent[i] = find(set, set->parent[i]);
    return set->parent[i];
}

// Union of two sets: O(alpha(N)) ~ O(1) average due to Union by Rank
void unionSets(DisjointSet *set, int i, int j) {
    int rootI = find(set, i);
    int rootJ = find(set, j);

    if (rootI != rootJ) {
        // Attach smaller rank tree under larger rank tree
        if (set->rank[rootI] < set->rank[rootJ]) {
            set->parent[rootI] = rootJ;
        } else if (set->rank[rootI] > set->rank[rootJ]) {
            set->parent[rootJ] = rootI;
        } else {
            set->parent[rootJ] = rootI;
            set->rank[rootI]++; // Increment rank if heights were equal
        }
        printf("Joined set containing %d with set containing %d\n", i, j);
    } else {
        printf("Nodes %d and %d are already in the same set!\n", i, j);
    }
}

// Free allocated memory
void freeSet(DisjointSet *set) {
    free(set->parent);
    free(set->rank);
    free(set);
}

int main() {
    printf("--- Session 12: Disjoint Set (Union-Find) ---\n\n");

    int N = 5;
    DisjointSet *set = createSet(N);

    // Initial partitions: {0}, {1}, {2}, {3}, {4}
    unionSets(set, 0, 2); // {0, 2}, {1}, {3}, {4}
    unionSets(set, 4, 2); // {0, 2, 4}, {1}, {3}
    unionSets(set, 1, 3); // {0, 2, 4}, {1, 3}

    printf("\nChecking Representatives:\n");
    printf("Representative of 0: %d\n", find(set, 0));
    printf("Representative of 4: %d\n", find(set, 4));
    printf("Representative of 3: %d\n", find(set, 3));
    
    // Check if 0 and 4 are in same set
    printf("\nAre 0 and 4 connected? %s\n", (find(set, 0) == find(set, 4)) ? "Yes" : "No");
    printf("Are 0 and 3 connected? %s\n", (find(set, 0) == find(set, 3)) ? "Yes" : "No");

    freeSet(set);

    printf("\nPress Enter to exit...");
    getchar();
    return 0;
}
