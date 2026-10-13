# Merge Two Sorted Lists

**Difficulty:** Easy | **Category:** Linked List
**LeetCode:** https://leetcode.com/problems/merge-two-sorted-lists/

## Problem Understanding
Merge two sorted linked lists into one sorted list by splicing together the existing
nodes (no new nodes created for values).

## Approach
Classic merge-step from merge sort, adapted to linked lists. Use a dummy head to
simplify result-building, and repeatedly attach whichever current node (from `list1`
or `list2`) has the smaller value, advancing that list's pointer.

## Algorithm
1. Dummy head, `current` pointer starts there.
2. While both lists have nodes remaining: attach the smaller-valued node to
   `current.next`, advance that source list, advance `current`.
3. Once one list is exhausted, attach the remainder of the other list directly (it's
   already sorted, no need to continue node-by-node).
4. Return `dummy.next`.

## Code
- [Solution.py](./Solution.py)
- [Solution.cpp](./Solution.cpp)
- [Solution.java](./Solution.java)

## Line-by-Line Explanation
- `<=` (not `<`) in the comparison doesn't affect correctness either way for stability
  here, but consistently picking `list1` on ties keeps behavior predictable.
- Attaching `list1 if list1 else list2` in one line handles "whichever list still has
  leftover nodes" without an extra loop, since a sorted list's remaining tail is
  already in sorted order.

## Dry Run
`list1 = 1->2->4`, `list2 = 1->3->4`

- 1(l1) ≤ 1(l2) → take l1's 1, l1 advances to 2.
- 2(l1) > 1(l2) → take l2's 1, l2 advances to 3.
- 2(l1) ≤ 3(l2) → take l1's 2, l1 advances to 4.
- 4(l1) > 3(l2) → take l2's 3, l2 advances to 4.
- 4(l1) ≤ 4(l2) → take l1's 4, l1 advances to null.
- l1 exhausted → attach remaining l2 (4).

Result: `1->1->2->3->4->4`.

## Complexity
- Time: O(m + n)
- Space: O(1) extra — nodes are relinked, not copied.

## Edge Cases
- One list is empty → result is simply the other list, returned via the final
  attach step (loop body never executes if one list starts empty).
- Both lists empty → returns `dummy.next` which is `None`/`null`.
