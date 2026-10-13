# Average of Levels in Binary Tree

**Difficulty:** Easy | **Category:** Binary Tree BFS
**LeetCode:** https://leetcode.com/problems/average-of-levels-in-binary-tree/

## Problem Understanding
Return the average node value of each level of the tree.

## Approach
Level-order BFS: process one level at a time, summing its values and dividing by the level size. The sum uses a floating-point (double) accumulator to avoid integer overflow on large values.

## Algorithm
1. Queue starts with `root` (the tree is non-empty per constraints).
2. For each level, pop `size` nodes, add their values, enqueue children.
3. Append `total / size` to the result.

## Code
- [Solution.py](./Solution.py)
- [Solution.cpp](./Solution.cpp)
- [Solution.java](./Solution.java)

## Dry Run
Tree `3 -> (9, 20 -> (15,7))`: level sums 3, 29, 22 over sizes 1, 2, 2 → `[3.0, 14.5, 11.0]`.

## Complexity
- Time: O(n)
- Space: O(w)

## Edge Cases
- Single node → its own value.
- Large values: double accumulator prevents 32-bit overflow.
