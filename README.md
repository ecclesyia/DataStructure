# Binus Data Structure Course Companion (Session-Based)

Welcome to the ultimate **Data Structures** course companion and repository! This project follows the session-based structure of the curriculum (inspired by your senior's format) and is designed specifically for **Binusian students** and anyone looking to master fundamental and advanced data structures in C.

This guide provides structured notes, setup tips, compilable C code examples, and side-by-side comparison examples in **C++**, **Java**, and **Python** to show how lower-level memory concepts translate into higher-level language primitives. We also integrate insights from **Harvard CS50** (making memory concrete) and **MIT 6.006** (algorithmic correctness and complexity).

---

## Getting Started & IDE Setup Guides
Before writing C code, configure your development environment:
* [**Dev-C++ Setup Guide (Recommended for Binus Exams)**](dev_c_setup.md) — Learn how to set up the default compiler, enable the C11 standard (`-std=c11`), and fix common compilation hangs.
* [**VS Code C Setup Guide**](vscode_c_setup.md) — Learn how to install MSYS2 GCC, add it to system environment PATH, and configure compilation tasks.

---

## Session-Based Course Modules

### [Session 01: Pointers, Memory, & Struct Recap](Session_01_PointersAndMemory/README.md)
* **Concepts**: Pointer referencing/dereferencing, pointer arithmetic, stack vs. heap, dynamic memory allocation (`malloc`, `free`), structs, and member access (`->`).
* **Side Examples**: Memory management comparison with C++ (references/smart pointers), Java (references), and Python (automatic reference counting/garbage collection).

### [Session 02: Singly Linked Lists](Session_02_SinglyLinkedList/README.md)
* **Concepts**: Dynamic reference chaining, nodes, list traversal, insertion (head, tail, mid), node deletion, and memory cleanup.
* **Side Examples**: Standard implementations in C++ (`std::list`), Java (`LinkedList`), and Python lists (which are dynamic arrays under the hood, contrasted with manual linked list classes).

### [Session 03: Doubly Linked Lists](Session_03_DoublyLinkedList/README.md)
* **Concepts**: Bidirectional chains (prev and next pointers), inserting and deleting in a doubly linked list, and edge case handling.
* **Side Examples**: Object-oriented doubly linked structures across C++, Java, and Python.

### [Session 04: Circular Linked Lists](Session_04_CircularLinkedList/README.md)
* **Concepts**: Circular reference loops, tail node pointing back to head, traversing circular lists, and loop termination condition checks.
* **Side Examples**: Round-robin scheduler queue applications in C++, Java, and Python.

### [Session 05: Stack & Queue](Session_05_StackAndQueue/README.md)
* **Concepts**: Stack LIFO (Last-In-First-Out) operations (push, pop, peek) and Queue FIFO (First-In-First-Out) operations (enqueue, dequeue, peek) implemented using dynamic linked lists.
* **Side Examples**: Standard library components: C++ (`std::stack`, `std::queue`), Java (`Stack`, `Queue`/`ArrayDeque`), and Python (`collections.deque`).

### [Session 06: Hash Tables (Collision: Chaining)](Session_06_HashTable_Chaining/README.md)
* **Concepts**: Hash functions, load factors, collision resolution using closed addressing (chaining linked lists to bucket slots), and searching.
* **Side Examples**: Built-in associative structures: C++ (`std::unordered_map`), Java (`HashMap`), and Python (`dict`).

### [Session 07: Hash Tables (Collision: Probing)](Session_07_HashTable_Probing/README.md)
* **Concepts**: Open addressing collision resolution: Linear Probing, Quadratic Probing, Double Hashing, clustering problem, and tombstone deletion.
* **Side Examples**: Array-based probing systems and hash set implementations.

### [Session 08: Binary Search Trees (BST)](Session_08_BinarySearchTree/README.md)
* **Concepts**: Hierarchical branching tree structures, BST property (left < parent < right), Depth-First Search (DFS) traversals (Pre-order, In-order, Post-order), and complex node deletion (0, 1, or 2 children cases).
* **Side Examples**: Ordered associative trees in C++ (`std::set`/`std::map`), Java (`TreeMap`), and Python.

### [Session 09: AVL Trees](Session_09_AVLTree/README.md)
* **Concepts**: Self-balancing BSTs, tree height tracks, Balance Factor calculation, and tree balancing via rotations: Single Left (LL), Single Right (RR), Double Left-Right (LR), and Double Right-Left (RL) rotations.
* **Side Examples**: Balancing tree concepts and standard library implementations.

### [Session 10: Heaps & Tries](Session_10_HeapsAndTries/README.md)
* **Concepts**: Array-represented Complete Binary Trees, Max/Min Heap properties, heapify up/down operations, Priority Queues, and Trie (Prefix Tree) structures for string search.
* **Side Examples**: Heap queues in C++ (`std::priority_queue`), Java (`PriorityQueue`), and Python (`heapq`).

### [Session 11: Graphs](Session_11_Graphs/README.md)
* **Concepts**: Graph terminology, representation techniques (Adjacency Matrix vs. Adjacency List), Breadth-First Search (BFS) using a queue, and Depth-First Search (DFS) using recursion/stack.
* **Side Examples**: Graph representations and traversal algorithms in modern OOP styles.

### [Session 12: Real-World Applications & Why Study Data Structures](Session_12_RealWorldApplications/README.md)
* **The Grand Schema**: Why we must understand data structures, how they leverage cache locality, memory layout details, and trade-offs.
* **Real-World Systems**: Database indices (B-Trees), network routers (shortest path graphs), OS schedulers, and Git (DAGs).
* **Advanced Concepts**: Disjoint Set Union-Find (with Path Compression and Union by Rank) and Minimum Spanning Trees (MST) using Kruskal's algorithm.

---

##  How to clone the repo
clone the repo:
1. **Clone this repo**: `git clone https://github.com/ecclesyia/DataStructure.git`
2. **Follow the IDE guide** first (VS Code or Dev-C++) so they do not get stuck trying to compile C code.
3. **Read the comments**: All source files are heavily annotated to explain pointer manipulation, memory allocation, and time complexity.
4. **Compare languages**: Inspect the `README.md` files to see how C concepts are simplified in higher-level languages.
