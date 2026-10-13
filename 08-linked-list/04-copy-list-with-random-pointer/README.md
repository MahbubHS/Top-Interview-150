# Copy List with Random Pointer

**Difficulty:** Medium | **Category:** Linked List
**LeetCode:** https://leetcode.com/problems/copy-list-with-random-pointer/

## Problem Understanding
Deep-copy a linked list where each node has a `next` pointer AND a `random` pointer
that can point to *any* node in the list (or null). The copy must be entirely
independent new nodes, wired with the same relative structure.

## Approach
**Hash map from old node → new node.** The challenge is that a node's `random` target
might not have been created yet when we first visit it. Solve this in two passes:
first create all new nodes (values only, no links yet), recording the old→new mapping;
then, in a second pass, wire up each new node's `next` and `random` by looking up the
mapped counterparts of the *old* node's `next`/`random`.

## Algorithm
1. First pass: for every old node, create a corresponding new node (copy of `val`
   only), store `old_to_new[old] = new`.
2. Second pass: for every old node, set `old_to_new[old].next = old_to_new[old.next]`
   (or None if `old.next` is None) and similarly for `random`.
3. Return `old_to_new[head]`.

## Code
- [Solution.py](./Solution.py)
- [Solution.cpp](./Solution.cpp)
- [Solution.java](./Solution.java)

## Line-by-Line Explanation
- Splitting into two passes is what solves the "random might point forward" problem:
  by the time pass 2 runs, every old node already has its new counterpart available
  in the map, regardless of traversal order.
- `old_to_new.get(current.next)` naturally returns `None`/`nullptr` when `current.next`
  is `None`, since a `None` key was never inserted into the map — no explicit null
  check needed in Python (C++/Java use an explicit ternary/conditional for clarity).

## Dry Run
List: `7(random:null) -> 13(random:7) -> 11(random:1, but only 2 nodes here for
brevity)`... conceptually: pass 1 creates copies of every node with correct `val`;
pass 2 rewires each copy's `next`/`random` to point at the *copies* of whatever the
original pointed to, using the map as a translation table.

## Complexity
- Time: O(n) — two linear passes.
- Space: O(n) for the hash map (in addition to the O(n) output list itself).

## Edge Cases
- Empty list (`head = None`) → return `None` immediately.
- A node's `random` points to itself → correctly handled since the map lookup for
  that node returns its own new copy.
- All `random` pointers are `None` → second pass just sets every `random` to `None`.
