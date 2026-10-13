# Count Complete Tree Nodes

**Difficulty:** Medium | **Category:** Binary Tree General
**LeetCode:** https://leetcode.com/problems/count-complete-tree-nodes/

## Problem Understanding
Count the nodes of a **complete** binary tree (every level full except possibly the last, which is
filled left to right) in better than O(n) time.

## Approach
**Exploit the complete-tree structure.** If the leftmost path and rightmost path from a node have
the same length, that subtree is a *perfect* binary tree of that height, so it has exactly
`2^h - 1` nodes with no traversal. If they differ, count `1 + left + right` recursively. In a
complete tree, at least one child subtree is always perfect, so the recursion prunes heavily.

## Algorithm
1. Null → 0.
2. Measure `left_h` by walking `.left` repeatedly and `right_h` by walking `.right` repeatedly.
3. If equal → return `(1 << left_h) - 1`.
4. Otherwise return `1 + countNodes(root.left) + countNodes(root.right)`.

## Code
- [Solution.py](./Solution.py)
- [Solution.cpp](./Solution.cpp)
- [Solution.java](./Solution.java)

## Line-by-Line Explanation
- `1 << h` computes `2^h` cheaply; subtracting 1 gives the node count of a perfect tree of height h.
- Only one side of each recursive split needs real work; the other side hits the perfect-tree
  shortcut immediately.

## Dry Run
Complete tree with nodes 1..6: `1 -> (2 -> (4,5), 3 -> (6))`

- Root: left height 3, right height 2 → not equal → 1 + count(2) + count(3).
- count(2): left height 2, right height 2 → perfect → 3.
- count(3): left height 2, right height 1 → not equal → 1 + count(6) + count(null) = 1 + 1 + 0 = 2.

Total = 1 + 3 + 2 = `6`.

## Complexity
- Time: O(log² n) — up to O(log n) levels of recursion, each measuring heights in O(log n).
- Space: O(log n) recursion depth.

## Edge Cases
- Empty tree → 0.
- Perfect tree → answered immediately at the root.
- Last level with a single node on the far left → handled by the mismatched-height branch.
