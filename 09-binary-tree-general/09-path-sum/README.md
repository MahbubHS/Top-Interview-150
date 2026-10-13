# Path Sum

**Difficulty:** Easy | **Category:** Binary Tree General
**LeetCode:** https://leetcode.com/problems/path-sum/

## Problem Understanding
Determine whether the tree has a **root-to-leaf** path whose node values add up to `targetSum`.

## Approach
**DFS with a shrinking target.** Subtract each node's value from the target as you go down. When you
reach a leaf, the path works exactly if the remaining target equals the leaf's value.

## Algorithm
1. Null node → False (no path).
2. Leaf node → return `root.val == targetSum`.
3. Otherwise recurse into both children with `targetSum - root.val`; return True if either succeeds.

## Code
- [Solution.py](./Solution.py)
- [Solution.cpp](./Solution.cpp)
- [Solution.java](./Solution.java)

## Line-by-Line Explanation
- The leaf check must require **both** children to be null; a node with one child isn't a leaf, so
  the path can't stop there.
- `or` short-circuits, so the right subtree is only searched if the left fails.

## Dry Run
Tree `5 -> (4 -> (11 -> (7,2)), 8 -> (13, 4 -> (null,1)))`, `targetSum = 22`

- 5 → remaining 17; 4 → 13; 11 → 2; leaf 2: `2 == 2` → True.

Result: `True` (path 5→4→11→2).

## Complexity
- Time: O(n)
- Space: O(h) recursion depth.

## Edge Cases
- Empty tree → False (even when `targetSum` is 0).
- Negative values → work unchanged since we only compare exact equality at leaves.
- A path that hits the target at an internal node doesn't count.
