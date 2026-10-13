# Same Tree

**Difficulty:** Easy | **Category:** Binary Tree General
**LeetCode:** https://leetcode.com/problems/same-tree/

## Problem Understanding
Check whether two binary trees are identical: same shape and same node values at every
position.

## Approach
**Simultaneous recursion.** Walk both trees together. At each pair of positions the two
nodes must either both be null, or both exist with equal values and matching left and right
subtrees.

## Algorithm
1. Both null → True.
2. Exactly one null, or values differ → False.
3. Otherwise recurse on `(p.left, q.left)` and `(p.right, q.right)`; both must be True.

## Code
- [Solution.py](./Solution.py)
- [Solution.cpp](./Solution.cpp)
- [Solution.java](./Solution.java)

## Line-by-Line Explanation
- The first check handles matching empty positions (the base case that ends recursion).
- The second check catches both shape mismatches (one side missing) and value mismatches
  in one condition.
- `and` short-circuits: if the left subtrees differ, the right ones aren't even checked.

## Dry Run
`p = [1,2,3]`, `q = [1,2,3]`

- (1,1): values equal → recurse.
- (2,2): equal, children are (null,null) both → True.
- (3,3): equal, children (null,null) → True.

Result: `True`. For `q = [1,2,null,3]` shape differs at the second level → `False`.

## Complexity
- Time: O(min(n, m)) — stops at the first mismatch.
- Space: O(h) recursion depth.

## Edge Cases
- Both trees empty → True.
- One empty, one not → False.
- Same values but different structure (e.g. node as left child vs right child) → False.
