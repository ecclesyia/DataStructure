#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Struct for Adjacency List Node
typedef struct AdjListNode {
    int dest;
    struct AdjListNode *next;
} AdjListNode;

// Struct for Adjacency List (each index head pointer)
typedef struct AdjList {
    AdjListNode *head;
} AdjList;

// Struct for Graph
typedef struct Graph {
    int numVertices;
    AdjList *array;
} Graph;

// Helper to create a new Adjacency List Node
AdjListNode *newAdjListNode(int dest) {
    AdjListNode *newNode = (AdjListNode *)malloc(sizeof(AdjListNode));
    if (newNode == NULL) {
        printf("Memory allocation error!\n");
        exit(1);
    }
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

// Create a graph with V vertices
Graph *createGraph(int vertices) {
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->numVertices = vertices;
    
    // Allocate array of adjacency lists
    graph->array = (AdjList *)malloc(vertices * sizeof(AdjList));
    
    // Initialize each list head as NULL
    for (int i = 0; i < vertices; i++) {
        graph->array[i].head = NULL;
    }
    return graph;
}

// Add an edge to an undirected graph: O(1)
void addEdge(Graph *graph, int src, int dest) {
    // Add an edge from src to dest (prepend to head of list)
    AdjListNode *newNode = newAdjListNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    // Add an edge from dest to src (since graph is undirected)
    newNode = newAdjListNode(src);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

// Breadth-First Search (BFS) Traversal: O(V + E)
void BFS(Graph *graph, int startVertex) {
    printf("BFS Starting from Vertex %d: ", startVertex);

    // Create visited tracker array
    bool *visited = (bool *)calloc(graph->numVertices, sizeof(bool));
    
    // Queue structure (using a simple array-based queue)
    int *queue = (int *)malloc(graph->numVertices * sizeof(int));
    int front = 0;
    int rear = 0;

    // Enqueue starting vertex and mark visited
    visited[startVertex] = true;
    queue[rear++] = startVertex;

    while (front < rear) {
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);

        // Process all neighbors of currentVertex
        AdjListNode *temp = graph->array[currentVertex].head;
        while (temp != NULL) {
            int adjVertex = temp->dest;
            if (!visited[adjVertex]) {
                visited[adjVertex] = true;
                queue[rear++] = adjVertex; // Enqueue
            }
            temp = temp->next;
        }
    }
    printf("\n");
    
    free(visited);
    free(queue);
}

// Helper recursive function for DFS
void DFSUntil(Graph *graph, int vertex, bool visited[]) {
    visited[vertex] = true;
    printf("%d ", vertex);

    AdjListNode *temp = graph->array[vertex].head;
    while (temp != NULL) {
        int adjVertex = temp->dest;
        if (!visited[adjVertex]) {
            DFSUntil(graph, adjVertex, visited);
        }
        temp = temp->next;
    }
}

// Depth-First Search (DFS) Traversal: O(V + E)
void DFS(Graph *graph, int startVertex) {
    printf("DFS Starting from Vertex %d: ", startVertex);
    
    bool *visited = (bool *)calloc(graph->numVertices, sizeof(bool));

    DFSUntil(graph, startVertex, visited);
    printf("\n");

    free(visited);
}

// Free all memory allocated for the graph
void freeGraph(Graph *graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        AdjListNode *curr = graph->array[i].head;
        while (curr != NULL) {
            AdjListNode *temp = curr;
            curr = curr->next;
            free(temp);
        }
    }
    free(graph->array);
    free(graph);
}

int main() {
    // Constructing a graph with 5 vertices (0 to 4)
    // Nodes connections:
    // 0 --- 1 --- 3
    // |   / |
    // | /   |
    // 2 --- 4
    int V = 5;
    Graph *graph = createGraph(V);
    
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 4);

    printf("--- Session 11: Graph Traversals (Adjacency List) ---\n\n");

    BFS(graph, 0); // Expected BFS: 0 2 1 4 3 (depends on insertion order)
    DFS(graph, 0); // Expected DFS: 0 2 4 1 3 (depends on insertion order)

    freeGraph(graph);

    printf("\nPress Enter to exit...");
    getchar();
    return 0;
}
