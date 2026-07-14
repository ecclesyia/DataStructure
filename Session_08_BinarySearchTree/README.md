# 📂 Session 08: Binary Search Trees (BST)

In this session, we transition from linear structures (lists, stacks, queues) to **Hierarchical Structures**. We study **Binary Search Trees (BST)**, covering key-based insertions, depth-first traversals, and the complex node deletion process.

---

## 💡 Concepts Explained

### 1. The BST Property
A Binary Tree consists of nodes where each node has at most two children. A **Binary Search Tree** enforces a sorting rule:
* For any given node:
  * All values in its **left subtree** must be **less** than the node's value.
  * All values in its **right subtree** must be **greater** than the node's value.

```text
Visual Representation (BST):
       [ 50 ]
      /      \
   [ 30 ]  [ 70 ]
   /    \
[ 20 ] [ 40 ]
```

### 2. Depth-First Traversals (DFS)
* **Pre-order (Root ➡️ Left ➡️ Right)**: Used to copy or clone a tree structure.
* **In-order (Left ➡️ Root ➡️ Right)**: **CRITICAL**: Traverses the tree in sorted, ascending order!
* **Post-order (Left ➡️ Right ➡️ Root)**: Used to delete/free nodes (bottom-up cleanup).

### 3. Deletion Cases
Deleting a node in a BST is tricky and has three cases:
1. **Node is a Leaf (No Children)**: Simply free the node and set its parent's pointer to `NULL`.
2. **Node has One Child**: Bypass the node by linking its parent directly to its child, then free the node.
3. **Node has Two Children**: Find the **Predecessor** (largest value in left subtree) or **Successor** (smallest value in right subtree). Swap its value with the target node, then recursively delete the predecessor/successor node (which is guaranteed to have at most one child).

---

## 🎓 College Perspectives

### 🔴 Harvard CS50 Insight
In CS50, we learn how BSTs combine the best of both worlds.
* In a sorted array, searching is fast (\(O(\log N)\) binary search), but inserting a new element is slow (\(O(N)\) because we must shift elements).
* In a linked list, inserting is fast (\(O(1)\)), but searching is slow (\(O(N)\)).
* A **BST** offers both logarithmic search and logarithmic insertion (\(O(\log N)\) average time).

### 🟡 MIT 6.006 perspective
A BST can degrade into a linear list (called a **degenerate/skewed tree**) if elements are inserted in sorted order (e.g., inserting `10, 20, 30, 40` forms a single line). In this case, search time degrades to \(O(N)\). This issue is why computer scientists developed self-balancing trees like **AVL Trees** (Session 9).

---

## 🌐 Multi-Language Comparison: Side-by-Side

### 1. C++ (std::set / std::map)
In C++, `std::set` and `std::map` are implemented as **Red-Black Trees** (a balanced BST variant) to guarantee \(O(\log N)\) performance for insertion, deletion, and searching.
```cpp
#include <iostream>
#include <set>

int main() {
    std::set<int> mySet = {50, 30, 70};
    mySet.insert(40);

    // Iterating over std::set prints items in sorted order (In-order traversal!)
    for (int x : mySet) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}
```

### 2. Java (TreeSet / TreeMap)
In Java, `TreeSet` and `TreeMap` represent balanced binary search trees.
```java
import java.util.TreeSet;

public class Main {
    public static void main(String[] args) {
        TreeSet<Integer> tree = new TreeSet<>();
        tree.add(50);
        tree.add(30);
        
        System.out.println(tree.first()); // Smallest element: 30
        System.out.println(tree.last());  // Largest element: 50
    }
}
```

### 3. Python (Standard Libraries)
Python does not have a built-in BST container. We can define our own or use third-party libraries like `bintrees`.
```python
class Node:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None

def insert(root, val):
    if root is None:
        return Node(val)
    if val < root.val:
        root.left = insert(root.left, val)
    else:
        root.right = insert(root.right, val)
    return root
```

---

## 🏃 Code Examples
Check this file in this directory to run the code:
* [**`binary_search_tree.c`**](binary_search_tree.c) — A complete BST implementation (create, insert, search, delete with predecessor swap, and traversals) in C.
