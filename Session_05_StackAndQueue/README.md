# 📂 Session 05: Stack & Queue

In this session, we study **restricted-access linear structures**:
* **Stack**: A LIFO (Last-In-First-Out) structure.
* **Queue**: A FIFO (First-In-First-Out) structure.

We will implement both using dynamic linked lists to avoid fixed-size array limits.

---

## 💡 Concepts Explained

### 1. Stack (LIFO: Last-In-First-Out)
Elements are added and removed from the same end, called the **top**.
* **push**: Add an element to the top. \(O(1)\) complexity.
* **pop**: Remove the top element. \(O(1)\) complexity.
* **peek / top**: Read the top element without removing it. \(O(1)\) complexity.

```text
Visual Representation (Stack):
   [ Top ] ➡️ [ Data: 30 ]
             [ Data: 20 ]
             [ Data: 10 ]
```

### 2. Queue (FIFO: First-In-First-Out)
Elements are inserted at the **rear** and removed from the **front**.
* **enqueue**: Add an element to the rear. \(O(1)\) complexity (if keeping a tail/rear pointer).
* **dequeue**: Remove the front element. \(O(1)\) complexity.
* **peek / front**: Read the front element. \(O(1)\) complexity.

```text
Visual Representation (Queue):
[ Dequeue / Front ] ⬅️ [ Data: 10 ] ⬅️ [ Data: 20 ] ⬅️ [ Data: 30 ] ⬅️ [ Enqueue / Rear ]
```

---

## 🎓 College Perspectives

### 🔴 Harvard CS50 Insight
Stacks are critical for understanding how programs execute. The **Call Stack** is a stack that records active function executions. When you call a function, its variables are pushed onto the stack; when it returns, they are popped off. If you write an infinite recursion, the stack fills up, causing a **Stack Overflow**.

### 🟡 MIT 6.006 perspective
Stacks and queues are fundamental primitives for graph traversal algorithms:
* **Stacks** (LIFO) are used in **Depth-First Search (DFS)** to trace paths as deep as possible first.
* **Queues** (FIFO) are used in **Breadth-First Search (BFS)** to explore neighbors layer-by-layer.

---

## 🌐 Multi-Language Comparison: Side-by-Side

### 1. C++ (std::stack & std::queue)
C++ STL provides wrapper adapters that restrict list/deque behaviors.
```cpp
#include <iostream>
#include <stack>
#include <queue>

int main() {
    // 1. Stack
    std::stack<int> s;
    s.push(10);
    s.pop();

    // 2. Queue
    std::queue<int> q;
    q.push(10); // Enqueue
    q.pop();  // Dequeue
}
```

### 2. Java (Stack class & Queue interface)
In Java, we use `java.util.Stack` or the `Deque` interface (`ArrayDeque` implementation).
```java
import java.util.Stack;
import java.util.Queue;
import java.util.ArrayDeque;

public class Main {
    public static void main(String[] args) {
        // Stack
        Stack<Integer> stack = new Stack<>();
        stack.push(10);
        int val = stack.pop();

        // Queue
        Queue<Integer> queue = new ArrayDeque<>();
        queue.offer(10); // Enqueue
        int front = queue.poll(); // Dequeue
    }
}
```

### 3. Python (collections.deque)
In Python, using list `append()` and `pop()` is fine for a stack, but `pop(0)` for a queue takes \(O(N)\) time. Instead, we use `collections.deque` for true \(O(1)\) operations.
```python
from collections import deque

# Stack
stack = deque()
stack.append(10)      # Push
top = stack.pop()     # Pop

# Queue
queue = deque()
queue.append(10)      # Enqueue
front = queue.popleft() # Dequeue
```

---

## 🏃 Code Examples
Check these files in this directory to run the code:
* [**`stack.c`**](stack.c) — Dynamic Stack (push, pop, peek, isEmpty) using a Singly Linked List in C.
* [**`queue.c`**](queue.c) — Dynamic Queue (enqueue, dequeue, peek, isEmpty) using a Singly Linked List in C.
