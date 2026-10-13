# Construct Binary Tree from Inorder and Postorder Traversal

**Difficulty:** Medium | **Category:** Binary Tree General
**LeetCode:** https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

## Problem Understanding
Given the inorder and postorder traversals of a binary tree (unique values), rebuild the tree.

## Approach
**Mirror of the preorder+inorder problem.** Postorder is left, right, root — so reading it from the
**end** gives the root first, then the right subtree's nodes, then the left subtree's. Use the
inorder array (with a value→index map) to split each range, and build the **right** subtree before
the left because the pointer is walking backward through postorder.

## Algorithm
1. Map inorder values to indices; `post_idx` starts at the last element of `postorder`.
2. `build(lo, hi)`: if empty return null; take `postorder[post_idx--]` as root; find `mid`.
3. Build `right = build(mid+1, hi)` first, then `left = build(lo, mid-1)`.

## Code
- [Solution.py](./Solution.py)
- [Solution.cpp](./Solution.cpp)
- [Solution.java](./Solution.java)

## Line-by-Line Explanation
- Right-before-left is the one change from the preorder version; getting the order wrong assigns
  the wrong values to each side.
- The inorder range again decides emptiness and the split point.

## Dry Run
`inorder = [9,3,15,20,7]`, `postorder = [9,15,7,20,3]`

- Last of postorder = 3 → root. mid=1.
- Right `[2,4]`: next from end = 20 → root, right `[4,4]` = 7, left `[2,2]` = 15.
- Left `[0,0]`: next = 9.

Result: `3 -> (9, 20 -> (15, 7))`.

## Complexity
- Time: O(n)
- Space: O(n)

## Edge Cases
- Single node, skewed trees, and empty ranges all handled by the `lo > hi` check.
- Building left first would produce a wrong tree even though it looks symmetrical.
