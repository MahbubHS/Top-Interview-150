# Reverse Linked List II

**Difficulty:** Medium | **Category:** Linked List
**LeetCode:** https://leetcode.com/problems/reverse-linked-list-ii/

## Problem Understanding
Reverse only the sublist of nodes from position `left` to `right` (1-indexed,
inclusive), leaving the rest of the list untouched, in one pass.

## Approach
**"Head insertion" (a.k.a. dummy-anchored) in-place reversal.** Walk to just before
position `left` (call this node `prev`). Then repeatedly take the node right after
`current` (the sublist's first node, which stays fixed) and move it to right after
`prev` — this is a classic trick where the sublist "grows backward" one node at a time
without needing to track a separate reversed pointer chain.

## Algorithm
1. Dummy node before `head` (handles `left == 1` cleanly).
2. Advance `prev` `left-1` times to sit just before the sublist.
3. `current = prev.next` (this becomes the sublist's *last* node after reversal, since
   it never moves).
4. Repeat `right - left` times: unlink the node after `current`, and re-insert it
   immediately after `prev`.
5. Return `dummy.next`.

## Code
- [Solution.py](./Solution.py)
- [Solution.cpp](./Solution.cpp)
- [Solution.java](./Solution.java)

## Line-by-Line Explanation
- `current` never moves throughout the reversal — it ends up as the last node of the
  reversed section, which is exactly where it belongs (it was the first node before
  reversal).
- Each iteration performs a 3-step relink: detach `next_node` from `current`,
  splice it in right after `prev`, and update `prev.next` to point to it — effectively
  a single-node "move to front of sublist."

## Dry Run
`head = 1->2->3->4->5`, `left=2`, `right=4`

- prev advances once → prev=node(1). current=node(2).
- Iteration 1: nextNode=3. current.next=4 (skip 3). nextNode(3).next=prev.next(2).
  prev.next=3. List so far: 1->3->2->4->5.
- Iteration 2: nextNode=4 (current is still 2, current.next=4). current.next=5.
  nextNode(4).next=prev.next(3). prev.next=4. List: 1->4->3->2->5.

Result: `1->4->3->2->5`. ✓ (positions 2-4 reversed)

## Complexity
- Time: O(n) — single pass (at most one traversal to `left`, plus `right-left` moves).
- Space: O(1) — pure pointer manipulation, no new nodes.

## Edge Cases
- `left == right` → the inner loop runs 0 times, list unchanged.
- `left == 1` → dummy node handles reversing from the very head correctly.
- `right` equals the list length → reversal extends to the last node, still correct.
