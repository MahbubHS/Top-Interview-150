# Binary Tree Maximum Path Sum

**Difficulty:** Hard | **Category:** Binary Tree General
**LeetCode:** https://leetcode.com/problems/binary-tree-maximum-path-sum/

## Problem Understanding
A path is any sequence of connected nodes (it doesn't need to pass through the root or end at a
leaf, and each node appears at most once). Find the maximum sum over all non-empty paths. Values
can be negative.

## Approach
**Post-order DFS returning the best "downward gain".** For each node compute two things:
1. The best path that **bends at this node** (uses both children): `node.val + leftGain + rightGain`.
   This is a candidate for the global answer.
2. The best path that **continues upward** to the parent (can use at most one child):
   `node.val + max(leftGain, rightGain)`. This is what the function returns.
Negative child gains are clamped to 0 (better to skip that branch).

## Algorithm
1. `gain(node)`: null → 0.
2. `left = max(gain(left), 0)`, `right = max(gain(right), 0)`.
3. Update global `best = max(best, node.val + left + right)`.
4. Return `node.val + max(left, right)`.

## Code
- [Solution.py](./Solution.py)
- [Solution.cpp](./Solution.cpp)
- [Solution.java](./Solution.java)

## Line-by-Line Explanation
- The returned value can't use both children because a path going up to the parent can only extend
  through one side; the "both children" version is only valid as a complete path ending here.
- Initializing `best` to negative infinity (not 0) matters when every node is negative.

## Dry Run
Tree `-10 -> (9, 20 -> (15, 7))`

- gain(15)=15, gain(7)=7 → at node 20: candidate 20+15+7 = 42; returns 20+15 = 35.
- gain(9)=9. At root -10: candidate -10 + 9 + 35 = 34; returns -10 + 35 = 25.
- best = 42.

Result: `42` (path 15→20→7).

## Complexity
- Time: O(n)
- Space: O(h) recursion depth.

## Edge Cases
- All negative values → the answer is the single largest (least negative) node, thanks to `best`
  starting at -infinity and clamping branches to 0 only when adding.
- Single node → that node's value.
- The best path may not include the root at all.
