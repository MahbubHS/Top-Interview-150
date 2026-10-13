# Populating Next Right Pointers in Each Node II

**Difficulty:** Medium | **Category:** Binary Tree General
**LeetCode:** https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/

## Problem Understanding
For any binary tree (not necessarily perfect), set each node's `next` pointer to the node
immediately to its right on the same level, or null if it's the rightmost. Ideally use O(1) extra
space.

## Approach
**Level-by-level linking using the `next` pointers you've already built.** Once a level is linked,
you can walk it left to right via `next` without a queue. While walking level L, stitch together
the children (level L+1) using a dummy-headed tail pointer. The dummy's `next` becomes the head of
the next level.

## Algorithm
1. `head` = leftmost node of the current level (starts at `root`).
2. Make a dummy node and `tail = dummy`.
3. Walk the current level with `cur` (via `next`); append `cur.left`, then `cur.right`, if they exist,
   to the chain at `tail`.
4. Set `head = dummy.next` to move to the next level; repeat until no more levels.

## Code
- [Solution.py](./Solution.py)
- [Solution.cpp](./Solution.cpp)
- [Solution.java](./Solution.java)

## Line-by-Line Explanation
- The dummy node removes the "is this the first child on the level?" special case: appending to
  `tail.next` always works and `dummy.next` naturally ends up as the leftmost child.
- Because the current level's `next` links were completed in the previous round, no queue is needed.

## Dry Run
Tree `1 -> (2 -> (4,5), 3 -> (null,7))`

- Level 1: only node 1; chain children → `2 -> 3`. head = 2.
- Level 2: walk 2 then 3; children 4, 5, 7 → `4 -> 5 -> 7`. head = 4.
- Level 3: nodes have no children → dummy.next null, loop ends.

## Complexity
- Time: O(n)
- Space: O(1) extra (the dummy is one node per level, reused conceptually).

## Edge Cases
- Empty tree → returns null immediately (`head` is null).
- Missing children (non-perfect tree) → simply skipped when stitching.
- Single node → its `next` stays null.
