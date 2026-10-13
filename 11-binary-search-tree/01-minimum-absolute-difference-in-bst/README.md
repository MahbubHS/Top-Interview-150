# Minimum Absolute Difference in BST

**Difficulty:** Easy | **Category:** Binary Search Tree
**LeetCode:** https://leetcode.com/problems/minimum-absolute-difference-in-bst/

## Problem Understanding
Find the smallest absolute difference between the values of any two different nodes in a BST.

## Approach
An inorder traversal of a BST visits values in sorted order, and the minimum difference must be between two **adjacent** values in that order. Track the previous value while traversing.

## Algorithm
1. Inorder traverse the tree.
2. Keep `prev` (the previously visited value).
3. At each node (after the first) update `best = min(best, node.val - prev)`.

## Code
- [Solution.py](./Solution.py)
- [Solution.cpp](./Solution.cpp)
- [Solution.java](./Solution.java)

## Dry Run
BST `[4,2,6,1,3]`: inorder is 1,2,3,4,6 → smallest gap is 1.

## Complexity
- Time: O(n)
- Space: O(h)

## Edge Cases
- Two-node tree → difference of the two values.
- Because inorder is ascending, `node.val - prev` is already non-negative.
