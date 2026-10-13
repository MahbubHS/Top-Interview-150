# Kth Smallest Element in a BST

**Difficulty:** Medium | **Category:** Binary Search Tree
**LeetCode:** https://leetcode.com/problems/kth-smallest-element-in-a-bst/

## Problem Understanding
Return the k-th smallest value (1-indexed) in a BST.

## Approach
Inorder traversal of a BST yields ascending order, so the k-th node visited is the answer. An iterative inorder with a stack lets us stop as soon as we hit the k-th node instead of visiting everything.

## Algorithm
1. Push the left spine onto a stack.
2. Pop a node, decrement `k`; if `k == 0`, return its value.
3. Move to the popped node's right child and repeat.

## Code
- [Solution.py](./Solution.py)
- [Solution.cpp](./Solution.cpp)
- [Solution.java](./Solution.java)

## Dry Run
BST `[3,1,4,null,2]`, k=1: leftmost is 1 → answer `1`. For `[5,3,6,2,4,null,null,1]`, k=3: order 1,2,3 → `3`.

## Complexity
- Time: O(h + k)
- Space: O(h)

## Edge Cases
- `k = 1` → the leftmost node.
- `k = n` → the rightmost node.
