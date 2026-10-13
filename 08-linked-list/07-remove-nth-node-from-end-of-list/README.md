# Remove Nth Node From End of List

**Difficulty:** Medium | **Category:** Linked List
**LeetCode:** https://leetcode.com/problems/remove-nth-node-from-end-of-list/

## Problem Understanding
Remove the `n`-th node from the **end** of the list and return the head, in a single
pass.

## Approach
**Two pointers with a fixed gap of `n`.** Advance a `fast` pointer `n` steps ahead
first. Then move `fast` and `slow` together until `fast` reaches the last node — at
that point, `slow` is sitting exactly one node before the target, ready to unlink it.
A dummy head handles the edge case of removing the very first node cleanly.

## Algorithm
1. Dummy node before `head`; `fast = slow = dummy`.
2. Advance `fast` by `n` steps (creates the gap).
3. While `fast.next` is not null, advance both `fast` and `slow` by one.
4. Now `slow.next` is the node to remove — unlink it: `slow.next = slow.next.next`.
5. Return `dummy.next`.

## Code
- [Solution.py](./Solution.py)
- [Solution.cpp](./Solution.cpp)
- [Solution.java](./Solution.java)

## Line-by-Line Explanation
- After the initial `n`-step head start, the gap between `fast` and `slow` stays
  constant at `n` throughout the second loop — so when `fast` is at the last node,
  `slow` is necessarily `n` nodes behind it, i.e., right before the node to delete.
- Using the dummy node means `slow` can legitimately end up *at* the dummy (when
  removing the head itself), and `dummy.next` still gives the correct new head.

## Dry Run
`head = 1->2->3->4->5`, `n = 2`

- fast starts at dummy, advances 2 steps → fast=2.
- Loop: fast.next=3 exists → fast=3, slow=1(from dummy). fast.next=4 exists → fast=4,
  slow=2. fast.next=5 exists → fast=5, slow=3. fast.next=null → stop.
- slow(3).next = slow.next.next → 3's next becomes 5 (skipping 4).

Result: `1->2->3->5->None`.

## Complexity
- Time: O(L) where L is the list length — single pass.
- Space: O(1)

## Edge Cases
- Removing the head (`n == length`) → dummy node makes this seamless, fast pointer's
  head start naturally positions slow at the dummy.
- Single-node list with `n = 1` → result is an empty list (`dummy.next` becomes null).
