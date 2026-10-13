# Binary Search Tree Iterator

**Difficulty:** Medium | **Category:** Binary Tree General
**LeetCode:** https://leetcode.com/problems/binary-search-tree-iterator/

## Problem Understanding
Design an iterator over a BST that yields values in **ascending (inorder)** order, with `next()` and
`hasNext()` running in O(1) average time and O(h) memory (h = tree height).

## Approach
**Controlled inorder traversal with an explicit stack.** Instead of flattening the whole tree up
front (O(n) memory), keep a stack holding only the path of "pending" ancestors. The stack top is
always the next smallest value. After popping a node, its right subtree still has smaller-than-
ancestor values to visit, so push that subtree's left spine.

## Algorithm
1. Constructor: push the left spine of `root` (root, root.left, root.left.left, ...).
2. `next()`: pop the top node, push the left spine of its right child, return the node's value.
3. `hasNext()`: return whether the stack is non-empty.

## Code
- [Solution.py](./Solution.py)
- [Solution.cpp](./Solution.cpp)
- [Solution.java](./Solution.java)

## Line-by-Line Explanation
- `_push_left` walks all the way left, so the stack top is the smallest not-yet-returned value.
- Each node is pushed and popped exactly once overall, so `next()` is O(1) amortized.
- The stack never holds more than one root-to-leaf path, giving O(h) space.

## Dry Run
Tree `7 -> (3, 15 -> (9, 20))`

- Init: stack = [7, 3].
- next() → pop 3 (right child null) → returns 3. stack = [7].
- next() → pop 7, push left spine of 15: [15, 9] → returns 7.
- next() → pop 9 → 9. next() → pop 15, push 20 → 15. next() → 20. hasNext() → False.

## Complexity
- Time: O(1) amortized per `next()`/`hasNext()`.
- Space: O(h)

## Edge Cases
- Single-node tree → one `next()` then `hasNext()` is False.
- Left-skewed tree → stack holds all nodes at init (h = n), still consistent with O(h).
- `next()` is only called when `hasNext()` is True (per the problem).
