# Symmetric Tree

**Difficulty:** Easy | **Category:** Binary Tree General
**LeetCode:** https://leetcode.com/problems/symmetric-tree/

## Problem Understanding
Check whether a binary tree is a mirror image of itself around its center.

## Approach
**Compare the left and right subtrees as mirrors.** Two trees are mirrors when their roots have
equal values, the left child of one mirrors the right child of the other, and vice versa. This
is the Same Tree check with the children crossed.

## Algorithm
1. If the tree is empty, it's symmetric.
2. Call `mirror(root.left, root.right)`.
3. In `mirror(a, b)`: both null → True; one null or values differ → False; else return
   `mirror(a.left, b.right) and mirror(a.right, b.left)`.

## Code
- [Solution.py](./Solution.py)
- [Solution.cpp](./Solution.cpp)
- [Solution.java](./Solution.java)

## Line-by-Line Explanation
- Crossing the children (`a.left` with `b.right`) is what makes this a mirror test rather than
  an equality test.
- The same three-way structure as Same Tree (both null / one null or mismatch / recurse) keeps
  the code short and safe.

## Dry Run
Tree `1 -> (2 -> (3,4), 2 -> (4,3))`

- mirror(2,2): equal values → check mirror(3,3) and mirror(4,4).
- mirror(3,3): equal, children null → True. mirror(4,4): True.

Result: `True`. For `1 -> (2 -> (null,3), 2 -> (null,3))` the 3s are on the same side → `False`.

## Complexity
- Time: O(n)
- Space: O(h) recursion depth.

## Edge Cases
- Empty tree or single node → symmetric.
- Equal values but wrong arrangement (both children on the same side) → not symmetric.
