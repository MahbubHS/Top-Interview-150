# Binary Tree Zigzag Level Order Traversal

**Difficulty:** Medium | **Category:** Binary Tree BFS
**LeetCode:** https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

## Problem Understanding
Level-order traversal, but the direction alternates: level 1 left→right, level 2 right→left, and so on.

## Approach
Run the normal BFS (always enqueuing left then right) and simply reverse every second level's list before storing it. This keeps the traversal simple; only the output order flips.

## Algorithm
1. Same BFS as level order with a boolean `left_to_right = True`.
2. After collecting a level, reverse it when the flag is False.
3. Toggle the flag after each level.

## Code
- [Solution.py](./Solution.py)
- [Solution.cpp](./Solution.cpp)
- [Solution.java](./Solution.java)

## Dry Run
Tree `3 -> (9, 20 -> (15,7))` → `[[3],[20,9],[15,7]]`.

## Complexity
- Time: O(n)
- Space: O(n)

## Edge Cases
- Empty tree → `[]`.
- Single node → `[[val]]`.
