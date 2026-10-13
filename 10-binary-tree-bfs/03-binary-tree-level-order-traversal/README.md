# Binary Tree Level Order Traversal

**Difficulty:** Medium | **Category:** Binary Tree BFS
**LeetCode:** https://leetcode.com/problems/binary-tree-level-order-traversal/

## Problem Understanding
Return the node values grouped by level, from top to bottom and left to right within each level.

## Approach
Standard BFS. Fixing the loop count to the queue size at the start of each round cleanly separates one level from the next.

## Algorithm
1. Enqueue `root`.
2. Per round, read `size = len(queue)`, pop that many nodes into a `level` list, enqueue their children.
3. Append each `level` to the result.

## Code
- [Solution.py](./Solution.py)
- [Solution.cpp](./Solution.cpp)
- [Solution.java](./Solution.java)

## Dry Run
Tree `3 -> (9, 20 -> (15,7))` → `[[3],[9,20],[15,7]]`.

## Complexity
- Time: O(n)
- Space: O(n)

## Edge Cases
- Empty tree → `[]`.
- Skewed tree → one value per level.
