# 📂 Session 07: Hash Tables (Collision: Probing)

In this session, we explore **Open Addressing (Probing)**. Instead of using external linked lists, all elements are stored directly in the hash table array. If a collision occurs, we probe (search) for alternative empty slots in the table.

---

## 💡 Concepts Explained

### 1. Open Addressing Probing Strategies
When slot `hash(key)` is already occupied, we check other slots using:
* **Linear Probing**: Check the next consecutive slot: `(index + i) % TABLE_SIZE`.
  * *Drawback*: **Primary Clustering** (long chains of occupied slots form, degrading operations to \(O(N)\)).
* **Quadratic Probing**: Check slots using a quadratic offset: `(index + c1 * i + c2 * i^2) % TABLE_SIZE`. Helps reduce primary clustering.
* **Double Hashing**: Use a secondary hash function to determine the step size: `(index + i * hash2(key)) % TABLE_SIZE`. This provides the most uniform distribution.

### 2. The Tombstone Pattern (Crucial for Deletion)
In open addressing, if we delete a key, we cannot just set its slot to `EMPTY (NULL)`.
* **Why?** If key `B` collided with `A` and was probed to slot 5, setting `A` to `NULL` would make the search algorithm stop at `A`'s old slot, incorrectly reporting that `B` does not exist.
* **Solution**: Mark the deleted slot with a **Tombstone** flag (`DELETED`). The search continues past tombstones, but insertions can overwrite them!

```text
Visual Representation (Table size 5 - Search path for B after A is deleted):
Slot 0: NULL
Slot 1: [ TOMBSTONE (A was here) ] ➡️ Search doesn't stop here, continues probing!
Slot 2: [ B ]                      ➡️ B is found!
Slot 3: NULL
Slot 4: NULL
```

---

## 🎓 College Perspectives

### 🔴 Harvard CS50 Insight
Open addressing teaches us about memory structures. In systems without pointer overhead (like embedded hardware), storing all keys inside a flat array is highly advantageous because it has zero auxiliary memory overhead and excellent **Cache Locality** (contiguous memory is read faster by the CPU cache).

### 🟡 MIT 6.006 perspective
Open Addressing tables are highly sensitive to the **Load Factor (\(\alpha = N / M\))**. Because all items reside in the array, \(\alpha\) can never exceed `1.0`. In practice, if \(\alpha > 0.7\), the average search time rises exponentially due to collisions. Therefore, we must resize and **rehash** the table when it is 70% full to maintain \(O(1)\) lookup.

---

## 🌐 Multi-Language Comparison: Side-by-Side

### 1. Python (dict Internals)
Python's built-in dictionary `dict` uses Open Addressing with a customized pseudo-random probing formula rather than chaining.
```python
# Python dict uses flat arrays under the hood.
# It resolves collisions by probing.
# This makes Python dicts extremely memory efficient and fast due to CPU cache hits!
my_dict = {"A": 10, "B": 20}
```

### 2. C++ (Google's Abseil flat_hash_map)
While C++ `std::unordered_map` uses chaining, high-performance C++ codebases (like Google's Abseil library) use `flat_hash_map`, which implements Open Addressing (using quadratic probing/SIMD instructions) because it is much faster on modern hardware.
```cpp
// Google Abseil library flat_hash_map example concept:
// absl::flat_hash_map<int, std::string> map;
// Stores keys and values flat in memory, eliminating pointer hops.
```

### 3. Java (ThreadLocalMap)
While Java's `HashMap` uses chaining, Java internally implements `ThreadLocalMap` using Linear Probing for simplicity and performance since it usually stores few elements.
```java
// Java ThreadLocal uses a custom ThreadLocalMap which resolves 
// collisions using linear probing.
ThreadLocal<Integer> threadLocal = new ThreadLocal<>();
threadLocal.set(42);
```

---

## 🏃 Code Examples
Check this file in this directory to run the code:
* [**`hash_table_probing.c`**](hash_table_probing.c) — Hash Table implementation using Linear Probing with state tracking (EMPTY, OCCUPIED, DELETED) to support search, insert, and tombstone deletions.
