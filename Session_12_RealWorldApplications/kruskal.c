#include <stdio.h>
#include <stdlib.h>

// Structure to represent an edge in the graph
typedef struct Edge {
    int src, dest, weight;
} Edge;

// Structure to represent a graph as an edge list
typedef struct Graph {
    int V, E;
    Edge *edge;
} Graph;

// Helper to create a graph
Graph *createGraph(int V, int E) {
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->V = V;
    graph->E = E;
    graph->edge = (Edge *)malloc(E * sizeof(Edge));
    return graph;
}

// Struct representing subset elements for Union-Find
typedef struct Subset {
    int parent;
    int rank;
} Subset;

// Find representative with Path Compression
int find(Subset subsets[], int i) {
    if (subsets[i].parent != i) {
        subsets[i].parent = find(subsets, subsets[i].parent);
    }
    return subsets[i].parent;
}

// Union by Rank
void unionSets(Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank) {
        subsets[xroot].parent = yroot;
    } else if (subsets[xroot].rank > subsets[yroot].rank) {
        subsets[yroot].parent = xroot;
    } else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

// Compare function for qsort (sort edges by ascending weight)
int compareEdges(const void *a, const void *b) {
    Edge *aEdge = (Edge *)a;
    Edge *bEdge = (Edge *)b;
    return aEdge->weight - bEdge->weight;
}

// Kruskal's MST Algorithm: O(E log E)
void KruskalMST(Graph *graph) {
    int V = graph->V;
    Edge *result = (Edge *)malloc((V - 1) * sizeof(Edge)); // Will store the final MST edges
    int resultCount = 0; // Index for result[]
    int edgeIndex = 0;   // Index for sorted edges

    // 1. Sort all edges in non-decreasing order of weight
    qsort(graph->edge, graph->E, sizeof(graph->edge[0]), compareEdges);

    // Allocate memory for creating V subsets
    Subset *subsets = (Subset *)malloc(V * sizeof(Subset));
    for (int v = 0; v < V; ++v) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    // 2. Iterate through sorted edges, pick the smallest.
    // Stop when result edges reach V-1
    while (resultCount < V - 1 && edgeIndex < graph->E) {
        Edge nextEdge = graph->edge[edgeIndex++];

        int x = find(subsets, nextEdge.src);
        int y = find(subsets, nextEdge.dest);

        // If including this edge doesn't cause a cycle, add it to MST
        if (x != y) {
            result[resultCount++] = nextEdge;
            unionSets(subsets, x, y);
        }
        // Else discard the edge
    }

    // Print the constructed MST
    printf("Edges in the Minimum Spanning Tree (MST):\n");
    int minimumCost = 0;
    for (int i = 0; i < resultCount; ++i) {
        printf("%d -- %d == Weight: %d\n", result[i].src, result[i].dest, result[i].weight);
        minimumCost += result[i].weight;
    }
    printf("Total Cost of Minimum Spanning Tree: %d\n", minimumCost);

    free(subsets);
    free(result);
}

int main() {
    // Constructing a weighted graph with 4 vertices and 5 edges
    //       10
    //    0------1
    //    | \    |
    //   6|  \5  |15
    //    |   \  |
    //    2------3
    //       4
    int V = 4;
    int E = 5;
    Graph *graph = createGraph(V, E);

    // edge 0-1
    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;
    graph->edge[0].weight = 10;

    // edge 0-2
    graph->edge[1].src = 0;
    graph->edge[1].dest = 2;
    graph->edge[1].weight = 6;

    // edge 0-3
    graph->edge[2].src = 0;
    graph->edge[2].dest = 3;
    graph->edge[2].weight = 5;

    // edge 1-3
    graph->edge[3].src = 1;
    graph->edge[3].dest = 3;
    graph->edge[3].weight = 15;

    // edge 2-3
    graph->edge[4].src = 2;
    graph->edge[4].dest = 3;
    graph->edge[4].weight = 4;

    printf("--- Session 12: Kruskal's Minimum Spanning Tree ---\n\n");
    KruskalMST(graph);

    free(graph->edge);
    free(graph);

    printf("\nPress Enter to exit...");
    getchar();
    return 0;
}
