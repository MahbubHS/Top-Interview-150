# Rotate List

**Difficulty:** Medium | **Category:** Linked List
**LeetCode:** https://leetcode.com/problems/rotate-list/

## Problem Understanding
Rotate the list to the right by `k` places — the last `k` nodes move to the front,
preserving their relative order.

## Approach
**Make it circular, then cut at the right spot.** Find the list's length and its tail;
link the tail back to the head to form a cycle. The new tail is at position
`length - k - 1` (0-indexed) from the old head; the node after it becomes the new
head. Breaking the cycle there completes the rotation.

## Algorithm
1. Handle trivial cases: empty list or single node → return as-is.
2. Walk to the tail, counting `length`.
3. Normalize `k %= length` (rotating by a multiple of the length is a no-op); if 0,
   return `head` unchanged.
4. Link `tail.next = head` (circular).
5. Walk `length - k - 1` steps from `head` to find the new tail; the node after it is
   the new head.
6. Cut the new tail's `next` to `None`, return the new head.

## Code
- [Solution.py](./Solution.py)
- [Solution.cpp](./Solution.cpp)
- [Solution.java](./Solution.java)

## Line-by-Line Explanation
- `k %= length` is essential: `k` can be arbitrarily larger than the list length, and
  rotating by exactly `length` steps returns to the original list.
- The circular trick avoids any special-casing for wraparound — once linked into a
  ring, "the last k nodes move to the front" is just "cut the ring at a different
  point."

## Dry Run
`head = 1->2->3->4->5`, `k = 2`

- length=5. k%=5 → k=2 (unchanged, less than length).
- Circular: 5.next=1.
- stepsToNewTail = 5-2 = 3 → newTail after 2 more steps from head(1): 1→2→3. newTail=3.
- newHead = newTail.next = 4.
- newTail.next = None → cuts ring: 3->None.

Result: `4->5->1->2->3`.

## Complexity
- Time: O(n) — one pass to find length, one pass to find the new tail.
- Space: O(1)

## Edge Cases
- `k` is a multiple of the list length → no rotation needed, returns original head.
- Single-node list → returned unchanged regardless of `k` (handled by the early
  `head.next is None` check).
- `k = 0` → returned unchanged.
