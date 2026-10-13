# Maximum Depth of Binary Tree

**Difficulty:** Easy | **Category:** Binary Tree General
**LeetCode:** https://leetcode.com/problems/maximum-depth-of-binary-tree/

## Problem Understanding
Return the maximum depth of a binary tree — the number of nodes along the longest path
from the root down to the farthest leaf.

## Approach
**Recursion (DFS).** The depth of a tree is 1 (for the root) plus the deeper of its two
subtrees' depths. An empty tree has depth 0, which is the base case.

## Algorithm
1. If `root` is null, return 0.
2. Recursively compute the depth of the left and right subtrees.
3. Return `1 + max(leftDepth, rightDepth)`.

## Code
- [Solution.py](./Solution.py)
- [Solution.cpp](./Solution.cpp)
- [Solution.java](./Solution.java)

## Line-by-Line Explanation
- The null check is the base case that stops the recursion at leaves' children.
- `1 + max(...)` counts the current node and then follows whichever branch is deeper.

## Dry Run
Tree: `3 -> (9, 20 -> (15, 7))`

- depth(9) = 1, depth(15) = 1, depth(7) = 1
- depth(20) = 1 + max(1, 1) = 2
- depth(3) = 1 + max(1, 2) = 3

Result: `3`.

## Complexity
- Time: O(n) — every node visited once.
- Space: O(h) recursion stack, where h is the tree height (O(n) worst case for a skewed tree).

## Edge Cases
- Empty tree → 0.
- Single node → 1.
- Fully skewed tree (linked-list shape) → depth equals n.
