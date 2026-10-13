# Reverse Nodes in k-Group

**Difficulty:** Hard | **Category:** Linked List
**LeetCode:** https://leetcode.com/problems/reverse-nodes-in-k-group/

## Problem Understanding
Reverse the nodes of a linked list in groups of `k`. If the number of nodes remaining
isn't a multiple of `k`, leave the final short group as-is (don't reverse it).

## Approach
Process one group at a time. For each group: first check whether `k` nodes actually
exist ahead (walk forward `k` steps from the end of the previous group) — if not,
we're done. Otherwise, reverse exactly that group in place (same technique as Reverse
Linked List II, bounded by the group's known start/end), then splice it back between
the previous group's end and the next group's start.

## Algorithm
1. Dummy node before `head`; `prev_group_end` tracks the last node of the already
   -processed portion (starts at dummy).
2. Loop: walk `k` steps from `prev_group_end` to find `kth` (the group's last node
   before reversal). If we run out of nodes before reaching k, return `dummy.next`
   (leftover partial group stays unreversed).
3. Record `group_start` (= `prev_group_end.next`, first node of this group) and
   `next_group_start` (= `kth.next`, first node of the *next* group).
4. Reverse the group: standard pointer-reversal, initializing `prev = next_group_start`
   so the last reversed node correctly links forward to the next group instead of null.
5. Splice: `prev_group_end.next = kth` (kth is now this group's head after reversal);
   `prev_group_end = group_start` (group_start is now this group's tail, becoming the
   anchor for the next iteration).
6. Repeat from step 2.

## Code
- [Solution.py](./Solution.py)
- [Solution.cpp](./Solution.cpp)
- [Solution.java](./Solution.java)

## Line-by-Line Explanation
- Pre-checking that `k` nodes exist (returning early if `kth` becomes null) is what
  correctly leaves a trailing short group untouched.
- Seeding `prev = next_group_start` before the reversal loop means the *last* node
  processed in the reversal (which becomes the new tail) automatically links to the
  right place — no separate "fix up the tail" step needed afterward.

## Dry Run
`head = 1->2->3->4->5`, `k = 2`

- Group 1 `[1,2]`: kth=2 found. Reverse → `2->1`, splicing gives `1->4...` wait — more
  precisely: after reversing, `dummy->2->1->(rest)`, and `prev_group_end` becomes node
  `1`.
- Group 2 `[3,4]`: kth=4 found. Reverse → `4->3`, splice gives `...1->4->3->(rest)`.
- Group 3 `[5]`: only 1 node found, `kth` becomes null before completing k=2 steps →
  return with `5` left untouched.

Result: `2->1->4->3->5`.

## Complexity
- Time: O(n) — every node is visited a constant number of times across all groups.
- Space: O(1) — pure in-place pointer manipulation.

## Edge Cases
- `k == 1` → each "group" is a single node; reversal loop does nothing meaningful,
  list unchanged.
- List length not a multiple of `k` → the final short group is correctly detected
  (kth becomes null) and left in original order.
- `k` equals the full list length → the entire list is reversed as one group.
