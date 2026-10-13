# Lowest Common Ancestor of a Binary Tree

**Difficulty:** Medium | **Category:** Binary Tree General
**LeetCode:** https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

## Problem Understanding
Given a binary tree (not necessarily a BST) and two nodes `p` and `q` that exist in it, find their
lowest common ancestor: the deepest node that has both as descendants (a node counts as a
descendant of itself).

## Approach
**Post-order search that reports what each subtree found.** Recurse into both subtrees. A call
returns `p` or `q` if it finds one in that subtree (or the LCA if both were found below). At a node:
- If both left and right recursions return something non-null, `p` and `q` are on different sides,
  so this node is the LCA.
- If only one side returns non-null, pass that result upward (it's either a single found node or an
  LCA already found deeper).

## Algorithm
1. If `root` is null, or is `p` or `q`, return `root`.
2. `left = LCA(root.left)`, `right = LCA(root.right)`.
3. If both non-null → return `root`.
4. Otherwise return whichever is non-null (or null).

## Code
- [Solution.py](./Solution.py)
- [Solution.cpp](./Solution.cpp)
- [Solution.java](./Solution.java)

## Line-by-Line Explanation
- Returning `root` as soon as it equals `p` or `q` is correct even if the other node is deeper below:
  a node is allowed to be its own ancestor, and the ancestor above will see the non-null result.
- Comparing nodes by identity (`is` / `==` on pointers), not by value, avoids problems if values
  repeat.

## Dry Run
Tree `3 -> (5 -> (6, 2 -> (7,4)), 1 -> (0,8))`, `p = 5`, `q = 1`

- At 3: left recursion returns 5 (found immediately), right recursion returns 1.
- Both non-null → return 3.

For `p = 5`, `q = 4`: the search under 5 finds 5 itself first and returns it; 3's right side returns
null, so the answer is 5 (a node is its own ancestor).

## Complexity
- Time: O(n)
- Space: O(h) recursion depth.

## Edge Cases
- One node is an ancestor of the other → that ancestor is returned.
- `p` and `q` are the same node → returns that node.
- Both nodes are guaranteed to exist (per constraints), so no "not found" handling is needed.
