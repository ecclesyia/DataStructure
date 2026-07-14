# 📂 Session 09: AVL Trees (Self-Balancing BST)

An **AVL Tree** (named after Adelson-Velsky and Landis) is a self-balancing Binary Search Tree. In this session, we study how AVL trees maintain logarithmic heights to guarantee \(O(\log N)\) search, insertion, and deletion speeds.

---

## Concepts Explained

### 1. The Height & Balance Factor (BF)
To remain balanced, each node in the tree tracks its own **Height** (the maximum number of edges from the node to a leaf).
* **Balance Factor (BF)**: `height(left_subtree) - height(right_subtree)`.
* **AVL Rule**: For *every* node in the tree, its Balance Factor must be **-1, 0, or 1**. If it becomes \(\ge 2\) or \(\le -2\), the tree is unbalanced and must be rotated.

```text
Unbalanced Tree (Height difference = 2):
       [ 50 ] (BF = 2)
      /
   [ 30 ] (BF = 1)
  /
[ 20 ] (BF = 0)
```

### 2. Rotations (LL, RR, LR, RL)
We rebalance the tree using pointer swaps called **Rotations**:
1. **Left-Left (LL) Violation**: Node's BF is `+2` and left child's BF is `+1`.
   * **Fix**: Perform a single **Right Rotation** on the unbalanced node.
2. **Right-Right (RR) Violation**: Node's BF is `-2` and right child's BF is `-1`.
   * **Fix**: Perform a single **Left Rotation** on the unbalanced node.
3. **Left-Right (LR) Violation**: Node's BF is `+2` and left child's BF is `-1`.
   * **Fix**: Perform a **Left Rotation** on the left child, then a **Right Rotation** on the node.
4. **Right-Left (RL) Violation**: Node's BF is `-2` and right child's BF is `+1`.
   * **Fix**: Perform a **Right Rotation** on the right child, then a **Left Rotation** on the node.

---

## College Perspectives

### Harvard CS50 Insight
In CS50, we learn that when we search a tree, we traverse down its height. If a BST is built in sorted order, it behaves like a linked list, taking \(O(N)\) time to search. By forcing the tree to balance itself upon every insertion (AVL concept), we ensure the height is always kept to the absolute minimum, guaranteeing that search paths never exceed \(O(\log N)\).

### MIT 6.006 perspective
MIT 6.006 provides the mathematical proof for AVL trees. The height \(H\) of an AVL tree with \(N\) nodes satisfies:
\[H \le 1.44 \log_2(N)\]
This means the height of the tree is strictly logarithmic. Rebalancing during insert/delete takes \(O(1)\) rotations per level, keeping the overhead for balancing inside the same \(O(\log N)\) asymptotic time boundary.

---

## Multi-Language Comparison: Side-by-Side

### 1. C++ (std::map / std::set) & Java (TreeMap) Internals
Both C++ STL (`std::map`) and Java Collections (`TreeMap`) use **Red-Black Trees** rather than AVL trees.
* **Why Red-Black Trees?** Red-Black trees are slightly less strictly balanced than AVL trees (allowing heights up to \(2 \log_2(N)\)). This means they require fewer rotations during insertions and deletions, making write operations slightly faster while keeping search at \(O(\log N)\).
* **When to use AVL?** AVL trees are faster for **read-heavy** workloads because they are more strictly balanced (smaller height = shorter lookup paths).

---

## 🏃 Code Examples
Check this file in this directory to run the code:
* [**`avl_tree.c`**](avl_tree.c) — A complete self-balancing AVL Tree (insert with LL, RR, LR, RL rotations, height checks, and print visualization) in C.
