# 📂 Session 02: Singly Linked Lists

Unlike contiguous static arrays, a **Singly Linked List** connects individual structures (nodes) scattered across the heap using pointers. This session covers node creation, insertion (head, tail, mid), deletion, search, and memory freeing.

---

## 💡 Concepts Explained

### 1. Structure of a Node
Each element in a Singly Linked List is called a **Node**. It contains two parts:
1. **Data**: The value or record we want to store.
2. **Next Pointer**: A pointer of type `struct Node *` that holds the address of the next node. The last node points to `NULL`.

```text
Visual Representation:
[ Head ] ➡️ [ Data: 10 | Next ] ➡️ [ Data: 20 | Next ] ➡️ [ Data: 30 | NULL ]
```

### 2. Basic Operations
* **pushHead**: Insert a new node at the very beginning. \(O(1)\) complexity.
* **pushTail**: Insert a new node at the end by traversing to the last node. \(O(N)\) complexity (or \(O(1)\) if keeping a tail pointer).
* **pushMid**: Insert a node at a specific sorted position or index. Requires traversal.
* **popHead / popTail / popMid**: Deletion operations that unlink a node from the chain and call `free()` on its address.

---

## 🎓 College Perspectives

### 🔴 Harvard CS50 Insight
In CS50, we learn that arrays have a fixed size. If we run out of space in an array, we must copy all elements to a new, larger array (which takes \(O(N)\) time). Linked lists solve this: we can dynamically allocate space for exactly one more element on the heap at any time and link it to the chain. The trade-off? Arrays have constant-time random access (\(O(1)\)), while linked lists require linear traversal (\(O(N)\)) from the head to find a specific element.

### 🟡 MIT 6.006 perspective
A linked list is a **Sequence** data structure. Under the word RAM model, while a dynamic array (like python `list`) has \(O(1)\) amortized insertion at the end and \(O(1)\) random access, a linked list provides strict \(O(1)\) insertion at the head. However, linked lists have poor cache locality because nodes are allocated randomly on the heap, causing CPU cache misses during traversal.

---

## 🌐 Multi-Language Comparison: Side-by-Side

Here is how Singly Linked Lists are handled in higher-level languages:

### 1. C++ (Standard STL list)
C++ STL provides `std::list` (which is a doubly linked list) and `std::forward_list` (which is a singly linked list).
```cpp
#include <iostream>
#include <forward_list>

int main() {
    std::forward_list<int> myList;

    // Insert at head
    myList.push_front(20);
    myList.push_front(10);

    // Print list elements
    for (int x : myList) {
        std::cout << "[" << x << "] -> ";
    }
    std::cout << "NULL" << std::endl;
}
```

### 2. Java (LinkedList Class)
Java provides `java.util.LinkedList` (which is implemented as a Doubly Linked List, but used similarly).
```java
import java.util.LinkedList;

public class Main {
    public static void main(String[] args) {
        LinkedList<Integer> list = new LinkedList<>();
        
        list.addFirst(10); // pushHead
        list.addLast(20);  // pushTail
        
        System.out.println(list); // Prints [10, 20]
    }
}
```

### 3. Python (Manual Node Construction)
Python's built-in `list` is a dynamic array (like a vector). To have a true linked list, we define a Node class:
```python
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class SinglyLinkedList:
    def __init__(self):
        self.head = None

    def push_head(self, data):
        new_node = Node(data)
        new_node.next = self.head
        self.head = new_node

# Usage
sll = SinglyLinkedList()
sll.push_head(20)
sll.push_head(10)
```

---

## 🏃 Code Examples
Check this file in this directory to run the code:
* [**`singly_linked_list.c`**](singly_linked_list.c) — A complete Singly Linked List (pushHead, pushTail, pushMid, popHead, popTail, popMid, print list, free memory) in C.
