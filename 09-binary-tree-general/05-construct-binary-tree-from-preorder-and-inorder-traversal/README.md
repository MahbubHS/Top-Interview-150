# Construct Binary Tree from Preorder and Inorder Traversal

**Difficulty:** Medium | **Category:** Binary Tree General
**LeetCode:** https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

## Problem Understanding
Given the preorder and inorder traversals of a binary tree (unique values), rebuild the tree.

## Approach
**Use preorder to pick roots, inorder to split subtrees.** In preorder the first unused value is
always the root of the current subtree. Finding that value in the inorder array splits it into a
left part (everything before) and a right part (everything after). A hash map from value to
inorder index makes each split an O(1) lookup.

## Algorithm
1. Map each inorder value to its index.
2. Keep a global pointer `pre_idx` into `preorder`.
3. `build(lo, hi)` builds the subtree covering inorder range `[lo, hi]`: if empty, return null;
   take `preorder[pre_idx++]` as the root, find its inorder position `mid`, then build the left
   subtree from `[lo, mid-1]` **first** and the right from `[mid+1, hi]`.

## Code
- [Solution.py](./Solution.py)
- [Solution.cpp](./Solution.cpp)
- [Solution.java](./Solution.java)

## Line-by-Line Explanation
- Building left before right matters: preorder visits root, then the whole left subtree, then the
  right subtree, so the shared pointer must be consumed in that order.
- The inorder range `[lo, hi]` only tells us when a subtree is empty and where to split.

## Dry Run
`preorder = [3,9,20,15,7]`, `inorder = [9,3,15,20,7]`

- Root 3 (mid=1): left range `[0,0]`, right range `[2,4]`.
- Left: root 9, empty children. Right: root 20 (mid=3) → left `[2,2]` = 15, right `[4,4]` = 7.

Result: `3 -> (9, 20 -> (15, 7))`.

## Complexity
- Time: O(n) with the hash map.
- Space: O(n) for the map and recursion.

## Edge Cases
- Single node → one call, no children.
- Fully left- or right-skewed trees → recursion depth n.
- Values must be unique (guaranteed), otherwise the inorder lookup is ambiguous.
