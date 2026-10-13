# Invert Binary Tree

**Difficulty:** Easy | **Category:** Binary Tree General
**LeetCode:** https://leetcode.com/problems/invert-binary-tree/

## Problem Understanding
Mirror a binary tree: swap the left and right child of every node, and return the root.

## Approach
**Recursive swap.** Inverting a tree means inverting each subtree and then swapping which side
they hang on. The recursion does the deep work; the swap at each node does the mirroring.

## Algorithm
1. If `root` is null, return null.
2. Invert the left subtree and the right subtree recursively.
3. Assign the inverted right subtree to `root.left` and the inverted left subtree to `root.right`.
4. Return `root`.

## Code
- [Solution.py](./Solution.py)
- [Solution.cpp](./Solution.cpp)
- [Solution.java](./Solution.java)

## Line-by-Line Explanation
- In C++/Java we store both recursive results in temporaries before reassigning, so we never
  overwrite a child pointer before we've used it.
- Python's tuple assignment evaluates the right-hand side fully first, giving the same safety.

## Dry Run
Tree `4 -> (2 -> (1,3), 7 -> (6,9))`

- Invert leaves 1,3,6,9 → unchanged.
- Node 2 becomes `2 -> (3,1)`; node 7 becomes `7 -> (9,6)`.
- Root swaps: `4 -> (7 -> (9,6), 2 -> (3,1))`.

## Complexity
- Time: O(n)
- Space: O(h) recursion depth.

## Edge Cases
- Empty tree → returns null.
- Single node → unchanged.
- Skewed tree → left-skewed becomes right-skewed.
