# 📂 Session 10: Heaps & Tries

In this session, we cover two highly practical structures:
1. **Binary Heap**: An array-represented tree optimized for priority lookups.
2. **Trie (Prefix Tree)**: A branching character search tree optimized for text matching.

---

## 💡 Concepts Explained

### 1. Binary Heap (Max/Min Heap)
A binary heap is a **Complete Binary Tree** (filled level-by-level from left to right). Because it has no holes, we can represent it efficiently in a **Flat Array** without using child pointers!

* **Index Calculations (0-indexed)**:
  * For any node at index `i`:
    * **Left Child**: `2 * i + 1`
    * **Right Child**: `2 * i + 2`
    * **Parent**: `(i - 1) / 2`
* **Heap Properties**:
  * **Max Heap**: Parent key is always \(\ge\) children's keys. The maximum element is at index `0` (the root).
  * **Min Heap**: Parent key is always \(\le\) children's keys. The minimum element is at index `0`.
* **Operations**:
  * **insert**: Append to the end of the array, then **heapifyUp** (bubble up) to restore order: \(O(\log N)\).
  * **extractMax / extractMin**: Swap the root with the last element, remove the last element, then **heapifyDown** (sink down) the new root: \(O(\log N)\).

### 2. Trie (Prefix Tree)
A **Trie** is a specialized tree structure used to store strings. Each node represents a character, and descending paths form words.
* **Trie Node**: Typically contains an array of 26 node pointers (representing letters A-Z) and a boolean flag `isEndOfWord`.
* **Benefits**: Insert, search, and prefix matching take \(O(L)\) time, where \(L\) is the length of the string, regardless of how many millions of words are in the database!

---

## 🎓 College Perspectives

### 🔴 Harvard CS50 Insight
Tries show us structural space-time trade-offs. Storing a list of words in a Trie is incredibly fast for lookups (\(O(L)\)), but it consumes a significant amount of memory because every node allocates pointers for 26 potential children, many of which remain `NULL`.

### 🟡 MIT 6.006 perspective
Heaps are the core mechanism behind **Priority Queues**. In operating systems, tasks are scheduled based on priority. A Heap allows retrieving the highest priority task in \(O(1)\) time, updating priorities in \(O(\log N)\) time, and deleting items in \(O(\log N)\) time. It also forms the basis of **Heap Sort** (\(O(N \log N)\) sorting algorithm with \(O(1)\) auxiliary space).

---

## 🌐 Multi-Language Comparison: Side-by-Side

Here is how Priority Queues (Heaps) are used across languages:

### 1. C++ (std::priority_queue)
C++ STL provides `std::priority_queue`, which uses a Max Heap by default.
```cpp
#include <iostream>
#include <queue>

int main() {
    std::priority_queue<int> pq;
    pq.push(30);
    pq.push(10);
    pq.push(20);

    // Prints elements in descending order: 30, 20, 10
    while (!pq.empty()) {
        std::cout << pq.top() << " ";
        pq.pop();
    }
}
```

### 2. Java (PriorityQueue)
Java provides a `PriorityQueue` class, which uses a Min Heap by default.
```java
import java.util.PriorityQueue;

public class Main {
    public static void main(String[] args) {
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        pq.add(30);
        pq.add(10);
        pq.add(20);

        // Prints in ascending order: 10, 20, 30
        while (!pq.isEmpty()) {
            System.out.println(pq.poll());
        }
    }
}
```

### 3. Python (heapq)
Python provides the `heapq` module, which exposes heap algorithms on standard Python lists (Min Heap implementation).
```python
import heapq

pq = []
heapq.heappush(pq, 30)
heapq.heappush(pq, 10)
heapq.heappush(pq, 20)

# Extract minimum: prints 10, 20, 30
while pq:
    print(heapq.heappop(pq))
```

---

## 🏃 Code Examples
Check these files in this directory to run the code:
* [**`max_heap.c`**](max_heap.c) — A complete Max Heap implementation using a flat array, featuring heapifyUp, heapifyDown, insert, and extractMax in C.
* [**`trie.c`**](trie.c) — A complete Trie (Prefix Tree) featuring string insertion, search, and prefix matching (`startsWith`) in C.
