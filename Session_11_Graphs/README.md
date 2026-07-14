# 📂 Session 11: Graphs

A **Graph** is a non-linear data structure consisting of **Vertices (Nodes)** connected by **Edges**. In this session, we cover graph representations and the two primary traversal algorithms: **Breadth-First Search (BFS)** and **Depth-First Search (DFS)**.

---

## Concepts Explained

### 1. Graph Representations
* **Adjacency Matrix**: A 2D array of size \(V \times V\).
  * `matrix[i][j] = 1` if an edge exists between vertex `i` and `j`, else `0`.
  * *Trade-off*: Fast edge lookup (\(O(1)\)), but wasteful memory consumption (\(O(V^2)\)), especially for sparse graphs.
* **Adjacency List**: An array of size \(V\), where each index `i` contains a **Linked List** representing the neighbors of vertex `i`.
  * *Trade-off*: Memory efficient (\(O(V + E)\)), but finding a specific edge takes \(O(\text{degree}(v))\) time.

```text
Visual Representation (Adjacency List for V=3: 0-1, 0-2):
List[0]: -> [ 1 ] -> [ 2 ] -> NULL
List[1]: -> [ 0 ] -> NULL
List[2]: -> [ 0 ] -> NULL
```

### 2. Graph Traversals
* **Breadth-First Search (BFS)**: Starts at a root node and explores all neighbor nodes at the current depth level before moving to nodes at the next depth level.
  * **Mechanism**: Uses a **FIFO Queue** and a `visited` array.
  * **Asymptotic complexity**: \(O(V + E)\).
* **Depth-First Search (DFS)**: Starts at a root node and explores as far as possible along each branch before backtracking.
  * **Mechanism**: Uses a **LIFO Stack** or **Recursion** and a `visited` array.
  * **Asymptotic complexity**: \(O(V + E)\).

---

## College Perspectives

### Harvard CS50 Insight
In CS50, we encounter graphs when learning about social networks (degrees of separation) and web crawlers (crawling links is traversing a directed graph of URLs). Representing networks as graphs allows us to find connection paths using search logic.

### MIT 6.006 perspective
MIT 6.006 defines BFS and DFS as core algorithm building blocks:
* **BFS** is used to find the **Shortest Path** in an unweighted graph, since it expands outwards layer-by-layer.
* **DFS** is highly useful for **Cycle Detection** (detecting loops in networks or build scripts) and **Topological Sort** (resolving package dependencies, like scheduling compiler tasks).

---

## Multi-Language Comparison: Side-by-Side

Here is how Adjacency Lists are commonly represented in higher-level languages:

### 1. C++ (std::vector of std::vector)
In C++, dynamic vectors make creating adjacency lists extremely simple without manual pointer tracking.
```cpp
#include <iostream>
#include <vector>

int main() {
    int V = 4;
    std::vector<std::vector<int>> adj(V);

    // Add undirected edge between 0 and 1
    adj[0].push_back(1);
    adj[1].push_back(0);

    // Print neighbors of vertex 0
    for (int neighbor : adj[0]) {
        std::cout << neighbor << " ";
    }
}
```

### 2. Java (List of Lists)
In Java, we combine `ArrayList` or `LinkedList` structures:
```java
import java.util.ArrayList;
import java.util.List;

public class Main {
    public static void main(String[] args) {
        int V = 4;
        List<List<Integer>> adj = new ArrayList<>();
        for (int i = 0; i < V; i++) {
            adj.add(new ArrayList<>());
        }

        // Add edge
        adj.get(0).add(1);
        adj.get(1).add(0);

        System.out.println("Neighbors of 0: " + adj.get(0));
    }
}
```

### 3. Python (Dictionary of Lists)
Python allows using a dictionary where vertices map to lists of neighbors, providing dynamic label support out of the box.
```python
# Adjacency list representation
graph = {
    0: [1, 2],
    1: [0, 3],
    2: [0],
    3: [1]
}

# Print neighbors of 0
print(graph[0]) # Output: [1, 2]
```

---

## Code Examples
Check this file in this directory to run the code:
* [**`graph_bfs_dfs.c`**](graph_bfs_dfs.c) — Graph representation using Adjacency Lists in C, featuring full BFS (queue-based) and DFS (recursion-based) traversals.
