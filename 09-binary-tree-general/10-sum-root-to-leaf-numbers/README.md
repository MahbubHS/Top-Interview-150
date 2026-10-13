# Sum Root to Leaf Numbers

**Difficulty:** Medium | **Category:** Binary Tree General
**LeetCode:** https://leetcode.com/problems/sum-root-to-leaf-numbers/

## Problem Understanding
Each root-to-leaf path spells a number by concatenating node digits (e.g. path 1→2→3 is 123).
Return the sum of all such numbers.

## Approach
**DFS carrying the number built so far.** Moving down one level appends a digit, which is
`current * 10 + node.val`. At a leaf the running value is a complete number; add up the results
from both subtrees.

## Algorithm
1. `dfs(node, current)`: if null, return 0.
2. Update `current = current * 10 + node.val`.
3. If it's a leaf, return `current`.
4. Otherwise return `dfs(left, current) + dfs(right, current)`.

## Code
- [Solution.py](./Solution.py)
- [Solution.cpp](./Solution.cpp)
- [Solution.java](./Solution.java)

## Line-by-Line Explanation
- Passing `current` by value means each branch keeps its own prefix and no undo step is needed.
- Returning 0 for null lets a node with a single child work without special handling — the missing
  side just contributes nothing.

## Dry Run
Tree `4 -> (9 -> (5,1), 0)`

- Path 4→9→5 = 495, path 4→9→1 = 491, path 4→0 = 40.
- Sum = 495 + 491 + 40 = 1026.

## Complexity
- Time: O(n)
- Space: O(h) recursion depth.

## Edge Cases
- Single node → its own value.
- Leading zeros in a path (like 4→0) are fine since the arithmetic handles them naturally.
- Values fit in `int` per the problem constraints.
