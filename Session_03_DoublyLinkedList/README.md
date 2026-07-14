# 📂 Session 03: Doubly Linked Lists

In this session, we upgrade to **Doubly Linked Lists**, where each node contains pointers to both its successor (**next**) and predecessor (**prev**). This bidirectional connection enables backward traversals and easier deletions at the cost of additional memory.

---

## 💡 Concepts Explained

### 1. Structure of a Doubly Linked Node
Unlike Singly Linked Nodes, a Doubly Linked Node contains:
1. **Data**: The payload value.
2. **Next Pointer**: Address of the next node (or `NULL` if tail).
3. **Prev Pointer**: Address of the previous node (or `NULL` if head).

```text
Visual Representation:
NULL ⬅️ [ Prev | Data: 10 | Next ] ↔️ [ Prev | Data: 20 | Next ] ➡️ NULL
```

### 2. Advantages & Disadvantages
* **Advantages**:
  * Can be traversed in both directions (forward and backward).
  * Deleting a node given its pointer is a constant-time \(O(1)\) operation, because we can directly access its predecessor without traversing from the head.
* **Disadvantages**:
  * Increased memory overhead (each node requires two pointers instead of one).
  * Pointer updates are more complex during insertions and deletions, as we must maintain the integrity of both link directions.

---

## 🎓 College Perspectives

### 🔴 Harvard CS50 Insight
In CS50, we notice the memory footprint of our data structures. On a 64-bit system, a pointer occupies 8 bytes.
* In a **Singly Linked Node** containing an `int` (4 bytes) and a `next` pointer (8 bytes), we use **12 bytes** (plus struct alignment padding, making it 16 bytes).
* In a **Doubly Linked Node** containing an `int` (4 bytes), a `prev` pointer (8 bytes), and a `next` pointer (8 bytes), we use **20 bytes** (padded to 24 bytes). Pointers consume more space than the actual payload!

### 🟡 MIT 6.006 perspective
A Doubly Linked List with both a `head` and a `tail` pointer is a versatile sequential model. It allows \(O(1)\) insertion and deletion at both ends, making it the perfect foundation for building **Double-ended Queues (Deques)**.

---

## 🌐 Multi-Language Comparison: Side-by-Side

### 1. C++ (std::list)
In C++, the standard sequential list `std::list` is implemented as a Doubly Linked List.
```cpp
#include <iostream>
#include <list>

int main() {
    std::list<int> dll;
    dll.push_back(10);  // Inserts at tail
    dll.push_front(5);  // Inserts at head

    // Iterating forward
    for (auto it = dll.begin(); it != dll.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}
```

### 2. Java (LinkedList)
Java's built-in `LinkedList` is doubly linked.
```java
import java.util.LinkedList;

public class Main {
    public static void main(String[] args) {
        LinkedList<String> dll = new LinkedList<>();
        dll.add("Middle");
        dll.addFirst("Head");
        dll.addLast("Tail");

        // LinkedList supports full listIterator for backward movement
        var iterator = dll.listIterator(dll.size());
        while (iterator.hasPrevious()) {
            System.out.println(iterator.previous());
        }
    }
}
```

### 3. Python (Manual Doubly Node Implementation)
Python does not provide a standard library Doubly Linked List class. We can build it like this:
```python
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
        self.prev = None

class DoublyLinkedList:
    def __init__(self):
        self.head = None
        self.tail = None

    def push_head(self, data):
        new_node = Node(data)
        if not self.head:
            self.head = self.tail = new_node
        else:
            new_node.next = self.head
            self.head.prev = new_node
            self.head = new_node
```

---

## 🏃 Code Examples
Check this file in this directory to run the code:
* [**`doubly_linked_list.c`**](doubly_linked_list.c) — A complete Doubly Linked List with insertions, deletions, forward print, and backward print.
