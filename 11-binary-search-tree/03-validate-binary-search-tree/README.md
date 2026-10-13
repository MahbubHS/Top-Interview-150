# Validate Binary Search Tree

**Difficulty:** Medium | **Category:** Binary Search Tree
**LeetCode:** https://leetcode.com/problems/validate-binary-search-tree/

## Problem Understanding
Check that every node is strictly greater than everything in its left subtree and strictly less than everything in its right subtree.

## Approach
Comparing a node only to its direct children is not enough. Pass down an allowed open interval `(low, high)`: going left tightens `high` to the parent value; going right raises `low`. Use a range wider than int (long) so node values equal to INT_MIN/INT_MAX still work.

## Algorithm
1. Start with the range `(-inf, +inf)`.
2. A node is invalid if `val <= low` or `val >= high`.
3. Recurse: left child gets `(low, val)`, right child gets `(val, high)`.

## Code
- [Solution.py](./Solution.py)
- [Solution.cpp](./Solution.cpp)
- [Solution.java](./Solution.java)

## Dry Run
`[5,1,4,null,null,3,6]`: node 3 lies in the right subtree of 5, so it must be `> 5` — it isn't → `False`.

## Complexity
- Time: O(n)
- Space: O(h)

## Edge Cases
- Duplicates (e.g. `[2,2,2]`) are invalid since ordering is strict.
- Node value `INT_MAX` or `INT_MIN` requires the wider bound type.
