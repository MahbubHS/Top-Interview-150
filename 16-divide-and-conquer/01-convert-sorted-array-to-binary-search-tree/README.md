# Convert Sorted Array to Binary Search Tree

**Difficulty:** Easy | **Category:** Divide & Conquer
**LeetCode:** https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

## Problem Understanding
Build a height-balanced BST from a sorted array (any valid balanced arrangement is accepted).

## Approach
**Divide and conquer on the array.** Picking the middle element as the root automatically balances
the tree: roughly half the remaining elements go left, half go right, and both halves are built the
same way recursively.

## Algorithm
1. `build(lo, hi)`: if `lo > hi`, return null.
2. `mid = (lo + hi) / 2`; create a node with `nums[mid]`.
3. `node.left = build(lo, mid-1)`, `node.right = build(mid+1, hi)`.

## Code
- [Solution.py](./Solution.py)
- [Solution.cpp](./Solution.cpp)
- [Solution.java](./Solution.java)

## Line-by-Line Explanation
- Always splitting at the midpoint keeps the two recursive halves within one element of each other in
  size, which is what guarantees height balance.
- Because the array is already sorted, no comparisons are needed — position alone determines the BST
  ordering.

## Dry Run
`nums = [-10,-3,0,5,9]`

mid index 2 → root 0. Left half `[-10,-3]` → root -3 (mid), left -10. Right half `[5,9]` → root 9
(mid=hi here with this rounding), left 5.

Result (one valid balanced tree): `0 -> (-3 -> (-10, None), 9 -> (5, None))`.

## Complexity
- Time: O(n)
- Space: O(log n) recursion depth (balanced by construction).

## Edge Cases
- Empty array → null tree.
- Single element → single node.
- Even-length array → either middle index is a valid, equally balanced choice.
