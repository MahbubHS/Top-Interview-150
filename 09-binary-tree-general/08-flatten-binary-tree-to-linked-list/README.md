# Flatten Binary Tree to Linked List

**Difficulty:** Medium | **Category:** Binary Tree General
**LeetCode:** https://leetcode.com/problems/flatten-binary-tree-to-linked-list/

## Problem Understanding
Flatten the tree in place into a "linked list" that uses only right pointers (left is null), with
nodes in **preorder** order.

## Approach
**Iterative rewiring (Morris-style).** For each node with a left subtree, the last node visited in
that left subtree (its rightmost node, the preorder predecessor of `cur.right`) should point to
`cur.right`. Then move the whole left subtree to the right side and clear left. Continue down the
right spine.

## Algorithm
1. `cur = root`.
2. If `cur.left` exists: find `pred`, the rightmost node in `cur.left`.
3. Set `pred.right = cur.right`, `cur.right = cur.left`, `cur.left = None`.
4. Move `cur = cur.right` and repeat until null.

## Code
- [Solution.py](./Solution.py)
- [Solution.cpp](./Solution.cpp)
- [Solution.java](./Solution.java)

## Line-by-Line Explanation
- In preorder, after finishing the left subtree the next node is the original right child — so the
  left subtree's last node must link to it; that's exactly `pred.right = cur.right`.
- Moving the left subtree to the right and nulling left completes the flatten for this node; deeper
  nodes get handled as `cur` walks down.

## Dry Run
Tree `1 -> (2 -> (3,4), 5 -> (null,6))`

- cur=1: pred = 4 (rightmost of 2's subtree). 4.right = 5. 1.right = 2. 1.left = null.
- cur=2: pred = 3. 3.right = 4. 2.right = 3. 2.left = null.
- cur=3, 4, 5, 6 have no left children.

Result: `1 -> 2 -> 3 -> 4 -> 5 -> 6` (all via right pointers).

## Complexity
- Time: O(n) — each edge along a rightmost path is walked a bounded number of times overall.
- Space: O(1) — no recursion or stack.

## Edge Cases
- Empty tree → nothing to do.
- Tree with only right children → already flat.
- Tree with only left children → each left is moved to right in turn.
