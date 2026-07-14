# 📂 Session 04: Circular Linked Lists

A **Circular Linked List** is a variation where the last node links back to the first node instead of pointing to `NULL`. This creates a closed loop, which is useful for applications requiring continuous cycle traversals (like schedulers).

---

## 💡 Concepts Explained

### 1. Singly vs. Doubly Circular Linked Lists
* **Singly Circular Linked List**: The `next` pointer of the tail node points back to the `head`.
* **Doubly Circular Linked List**: The `next` pointer of the tail points to `head`, and the `prev` pointer of the `head` points to the tail.

```text
Visual Representation (Singly Circular):
┌──────────────────────────────────────┐
│                                      ▼
[ Head ] ➡️ [ Data: 10 ] ➡️ [ Data: 20 ] ➡️ [ Data: 30 ] ──┘
```

### 2. Crucial Traversal Logic
Because there is no `NULL` endpoint, standard `while(curr != NULL)` loops will run forever (an **infinite loop**).
* **Fix**: Save the address of the `head` node, and stop the traversal when `curr->next` (or `curr`) returns to the starting `head` node.

```c
Node *curr = head;
if (head != NULL) {
    do {
        printf("%d -> ", curr->data);
        curr = curr->next;
    } while (curr != head);
}
```

---

## 🎓 College Perspectives

### 🔴 Harvard CS50 Insight
In CS50, we emphasize debugging. When working with circular lists, a common bug is the "off-by-one" error where the last node's content isn't printed, or the loop fails to run at all because `curr` is initialized to `head` and the condition check `curr != head` fails immediately. This is why we use a `do-while` loop in C: it guarantees the block runs at least once before checking the boundary condition.

### 🟡 MIT 6.006 perspective
Circular lists are excellent for representing **Ring Buffers** and circular queues. Because they have no absolute "start" or "end," we can shift the "current active node" pointer in \(O(1)\) time, representing circular round-robin scheduling algorithms without needing to re-order the structural data.

---

## 🌐 Multi-Language Comparison: Side-by-Side

### 1. C++ (Simulating Ring Iterator)
C++ doesn't have a built-in circular container, but we can simulate circular traversals on a standard `std::list`:
```cpp
#include <iostream>
#include <list>

int main() {
    std::list<int> myList = {10, 20, 30};

    auto it = myList.begin();
    for (int i = 0; i < 10; ++i) { // Cycle 10 times
        std::cout << *it << " -> ";
        ++it;
        if (it == myList.end()) {
            it = myList.begin(); // Wrap around
        }
    }
    std::cout << "..." << std::endl;
}
```

### 2. Java (Circular Queue Buffer Simulation)
We can build circular traversal wrappers around List iterators or index calculations:
```java
import java.util.List;

public class Main {
    public static void main(String[] args) {
        List<Integer> list = List.of(10, 20, 30);
        int index = 0;
        
        for (int i = 0; i < 10; i++) {
            System.out.print(list.get(index) + " -> ");
            index = (index + 1) % list.size(); // Circular modulo arithmetic
        }
        System.out.println("...");
    }
}
```

### 3. Python (Itertools Cycle)
Python's standard library provides a highly optimized utility `itertools.cycle` to turn any sequence into an infinite circular generator.
```python
from itertools import cycle

my_list = [10, 20, 30]
pool = cycle(my_list)

# Fetch first 10 circular elements
for _ in range(10):
    print(next(pool), end=" -> ")
print("...")
```

---

## 🏃 Code Examples
Check this file in this directory to run the code:
* [**`circular_linked_list.c`**](circular_linked_list.c) — A complete Singly Circular Linked List with pushHead, pushTail, popHead, print list, and cleanup in C.
