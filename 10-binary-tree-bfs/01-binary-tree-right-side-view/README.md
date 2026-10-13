# Binary Tree Right Side View

**Difficulty:** Medium | **Category:** Binary Tree BFS
**LeetCode:** https://leetcode.com/problems/binary-tree-right-side-view/

## Problem Understanding
Return the values of the nodes you would see standing on the right side of the tree, top to bottom.

## Approach
The visible node on each level is the **last node of that level**. Do a level-order (BFS) traversal and record the final node processed per level.

## Algorithm
1. Start a queue with `root`.
2. For each level, process exactly `size = len(queue)` nodes.
3. When the index is the last of the level, append its value.
4. Enqueue children (left then right).

## Code
- [Solution.py](./Solution.py)
- [Solution.cpp](./Solution.cpp)
- [Solution.java](./Solution.java)

## Dry Run
Tree `1 -> (2 -> (null,5), 3 -> (null,4))`: levels are [1], [2,3], [5,4]; last of each = `[1,3,4]`.

## Complexity
- Time: O(n)
- Space: O(w) where w is the maximum tree width

## Edge Cases
- Empty tree → `[]`.
- Left-only branches on a level with no right node are still visible (last node in that level).
