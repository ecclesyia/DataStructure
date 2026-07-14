# 📂 Session 01: Pointers, Memory, & Struct Recap

Before building complex data structures, we must master how C programs manage memory. In this session, we recap **Pointers**, the difference between the **Stack and Heap**, and how **Structures** act as building blocks for nodes.

---

## 💡 Concepts Explained

### 1. Pointers: Referencing and Dereferencing
A pointer is simply a variable that stores the memory address of another variable.
* **Address-of Operator (`&`)**: Extracts the memory address of a variable.
* **Dereference Operator (`*`)**: Accesses the value stored at the address pointed to.

```c
int num = 42;
int *ptr = &num; // ptr stores the address of num

printf("Address: %p\n", ptr); // Prints hex address, e.g., 0x7ffeefbff56c
printf("Value: %d\n", *ptr);   // Dereferences ptr to print 42
```

### 2. Stack vs. Heap Memory
Memory is divided into regions with distinct lifespans and behaviors:
* **Stack**: Automatically managed. Local variables are placed here. When a function returns, its stack frame is popped, and memory is automatically reclaimed.
* **Heap**: Manually managed. Used for dynamic memory allocations during runtime. Memory allocated on the heap remains active until it is explicitly freed.
  * `malloc(size)`: Allocates a block of memory of specified bytes on the heap. Returns a generic pointer `void *`.
  * `free(ptr)`: Releases the allocated block back to the system. Failure to call this causes a **Memory Leak**.

```text
Memory Grid Representation (CS50 Concept):
[ Stack (Local variables) ]  ➡️  Fast, small size, automatic cleanup.
[ Heap (malloc'ed blocks) ]  ➡️  Flexible, large size, must be manually freed!
```

### 3. Structures (`struct`) and the Arrow Operator (`->`)
Structures allow us to group variables of different types.
* When working with a pointer to a struct, we access its members using the **Arrow Operator (`->`)** instead of the dot (`.`) operator.

```c
typedef struct {
    char name[20];
    int score;
} Student;

Student s = {"Alice", 95};
Student *ptr = &s;

printf("%s\n", ptr->name); // Equivalent to (*ptr).name
```

---

## 🎓 College Perspectives

### 🔴 Harvard CS50 Insight
In CS50, we think of memory as a massive array of byte-sized drawers, each with a unique address. Pointers are "arrows" pointing to specific drawers. If you lose the arrow pointing to a block of heap memory (e.g., by reassigning a pointer before calling `free`), that memory becomes locked forever (a memory leak) until the program closes.

### 🟡 MIT 6.006 perspective
In algorithms, reading a memory address (pointer dereferencing) is treated as an \(O(1)\) constant-time operation. However, in physical hardware, dereferencing pointers that are scattered across different memory locations causes "cache misses," which are slower than accessing contiguous array elements (cache locality).

---

## 🌐 Multi-Language Comparison: Side-by-Side

Here is how modern languages handle objects, pointers, and memory compared to C:

### 1. C++ (Pointers & Smart Pointers)
C++ supports raw pointers just like C, but provides **References** and **Smart Pointers** for automatic memory management.
```cpp
#include <iostream>
#include <memory>

struct Student {
    std::string name;
    int score;
};

int main() {
    // 1. Reference (alias, cannot be null)
    int num = 42;
    int& ref = num; 

    // 2. Smart Pointer (automatically calls delete when out of scope)
    std::unique_ptr<Student> s = std::make_unique<Student>(Student{"Alice", 95});
    std::cout << s->name << std::endl; // Accesses via -> operator
    // No free() needed!
}
```

### 2. Java (Object References)
Java does not have raw pointers or manual memory management. Everything is an object reference, and unused memory is reclaimed by the Garbage Collector (GC).
```java
public class Main {
    static class Student {
        String name;
        int score;
        Student(String name, int score) {
            this.name = name;
            this.score = score;
        }
    }

    public static void main(String[] args) {
        // 's' is a reference variable, pointing to the Student object in heap
        Student s = new Student("Alice", 95);
        System.out.println(s.name); // Access using dot (.) operator
        // Garbage Collector handles freeing memory automatically!
    }
}
```

### 3. Python (References and Names)
In Python, variables are names bound to objects in memory. Garbage collection is handled automatically using Reference Counting.
```python
class Student:
    def __init__(self, name, score):
        self.name = name
        self.score = score

# 's' references a Student instance in heap
s = Student("Alice", 95)
print(s.name)
# Python automatically deletes the object when no variables reference it.
```

---

## 🏃 Code Examples
Check these files in this directory to run the code:
* [**`pointers_basics.c`**](pointers_basics.c) — Address referencing, pointer dereferencing, and pointer arithmetic.
* [**`dynamic_memory.c`**](dynamic_memory.c) — Dynamic allocation of structure records, resizing elements, and memory cleanup.
