# Partition List

**Difficulty:** Medium | **Category:** Linked List
**LeetCode:** https://leetcode.com/problems/partition-list/

## Problem Understanding
Rearrange a linked list so all nodes with value `< x` come before all nodes with
value `>= x`, preserving the original **relative order** within each group.

## Approach
**Build two separate lists, then join them.** Walk the original list once, routing
each node into either a "before" list (values `< x`) or an "after" list (values
`>= x`) using two dummy-anchored tails. Since we only ever append to the tail of
whichever list a node belongs to, relative order within each group is naturally
preserved. Finally, link the end of "before" to the start of "after."

## Algorithm
1. Two dummy heads: `before_head`, `after_head`; tail pointers `before`, `after`
   start there too.
2. For each node in the original list: append it to `before` or `after` based on
   `val < x`, and advance that tail pointer.
3. Terminate the "after" list with `None` (its last node might still point further
   into the original list otherwise).
4. Link `before`'s tail to `after_head.next` (the actual start of the after list).
5. Return `before_head.next`.

## Code
- [Solution.py](./Solution.py)
- [Solution.cpp](./Solution.cpp)
- [Solution.java](./Solution.java)

## Line-by-Line Explanation
- Reusing the *original* nodes (not copying values) means relative order is preserved
  "for free" — each node just gets relinked into one of two sub-lists in the order it
  was originally visited.
- `after.next = None` is essential: without it, the last node routed into "after"
  might still carry a stale `next` pointer to a node that got routed into "before,"
  creating an incorrect link or even a cycle.

## Dry Run
`head = 1->4->3->2->5->2`, `x = 3`

- 1<3 → before: 1
- 4≥3 → after: 4
- 3≥3 → after: 4->3
- 2<3 → before: 1->2
- 5≥3 → after: 4->3->5
- 2<3 → before: 1->2->2

before list: `1->2->2`, after list: `4->3->5`. Join: `1->2->2->4->3->5`.

## Complexity
- Time: O(n)
- Space: O(1) extra — nodes are relinked, not copied (dummy nodes are the only new
  allocations).

## Edge Cases
- All values `< x` → "after" list stays empty, result is the original list unchanged
  in order.
- All values `>= x` → "before" list stays empty, result is the original list.
- Empty list → both dummy tails stay at their heads, result is `None`.
