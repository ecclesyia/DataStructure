# 📂 Session 06: Hash Tables (Collision: Chaining)

A **Hash Table** maps keys to values for near constant-time \(O(1)\) lookup. This session covers hash functions and resolving collisions using **Chaining (Closed Addressing)**, where each slot in the hash table points to a Linked List.

---

## 💡 Concepts Explained

### 1. Hash Function & Collisions
* **Hash Function**: Computes an integer index from a key (e.g., transforming a name string into index `4`). A basic division method is `hashValue = key % TABLE_SIZE`.
* **Collision**: Occurs when two distinct keys yield the same hash index.

### 2. Chaining (Closed Addressing)
Instead of searching for alternative slots, we store all elements hashing to the same index in a **Linked List** at that bucket slot.

```text
Visual Representation (Hash Table Chaining with Size 5):
Index 0: NULL
Index 1: [ Key: "Siti" | Val: 101 ] ➡️ [ Key: "Clara" | Val: 105 ] ➡️ NULL
Index 2: NULL
Index 3: [ Key: "Budi" | Val: 102 ] ➡️ NULL
Index 4: NULL
```

---

## 🎓 College Perspectives

### 🔴 Harvard CS50 Insight
In CS50, the legendary **Spell Checker** assignment challenges students to load a massive dictionary into memory and check spelling errors in real-time. By implementing a Hash Table, the lookup time changes from a slow linear search \(O(N)\) or binary search \(O(\log N)\) to an average of \(O(1)\) constant time, verifying thousands of words in fractions of a second.

### 🟡 MIT 6.006 perspective
The **Dictionary Problem** is about maintaining a dynamic set under insertion, deletion, and search.
* **Birthday Paradox**: Shows that collisions are mathematically guaranteed to happen even with small load factors.
* **Load Factor (\(\alpha = N / M\))**: Represents the average chain length. Average search time is \(O(1 + \alpha)\). If \(N\) grows too large compared to bucket count \(M\), the hash table degrades to \(O(N)\). To fix this, we must **Rehash** (resize the table and re-index elements).

---

## 🌐 Multi-Language Comparison: Side-by-Side

### 1. C++ (std::unordered_map)
C++ implements its associative key-value map `std::unordered_map` using hash tables with chaining.
```cpp
#include <iostream>
#include <unordered_map>
#include <string>

int main() {
    std::unordered_map<std::string, int> scores;
    scores["Budi"] = 100;
    scores["Siti"] = 95;

    std::cout << "Budi's score: " << scores["Budi"] << std::endl;
}
```

### 2. Java (HashMap)
Java's `HashMap` uses chaining. **Crucial Optimization**: If a chain grows past 8 nodes, Java converts the linked list into a **Red-Black Tree** to prevent worst-case \(O(N)\) Denial of Service attacks, guaranteeing \(O(\log N)\) worst-case lookup.
```java
import java.util.HashMap;

public class Main {
    public static void main(String[] args) {
        HashMap<String, Integer> map = new HashMap<>();
        map.put("Budi", 100);
        
        if (map.containsKey("Budi")) {
            System.out.println("Found Budi: " + map.get("Budi"));
        }
    }
}
```

### 3. Python (dict)
Python's built-in `dict` is a highly optimized hash table that uses **Open Addressing** (probing) rather than chaining.
```python
# Creating dictionary
scores = {"Budi": 100, "Siti": 95}

# Fetching value
print(scores.get("Budi"))
```

---

## 🏃 Code Examples
Check this file in this directory to run the code:
* [**`hash_table_chaining.c`**](hash_table_chaining.c) — A complete Hash Table implementation using chaining (linked list buckets) for collision resolution.
