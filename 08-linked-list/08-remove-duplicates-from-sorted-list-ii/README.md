# Remove Duplicates from Sorted List II

**Difficulty:** Medium | **Category:** Linked List
**LeetCode:** https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/

## Problem Understanding
Given a **sorted** linked list, remove every node that has a duplicate value, leaving
only numbers that appear exactly once (unlike the array version, here duplicates are
removed *entirely*, not reduced to one copy).

## Approach
Use a dummy head plus a `prev` pointer that only advances onto nodes we're sure are
unique. Scan with `current`: whenever we detect `current.val == current.next.val`
(start of a duplicate run), skip forward past every node with that same value, then
relink `prev.next` directly to whatever comes after the whole run — entirely excising
it.

## Algorithm
1. Dummy head before `head`; `prev = dummy`, `current = head`.
2. While `current`: if `current.next` exists and shares `current`'s value, remember
   the value, skip `current` forward through every node with that value, then set
   `prev.next = current` (splicing past the entire duplicate run).
3. Otherwise (no duplicate starting here), advance `prev` to `current` and `current`
   forward by one — this node is confirmed unique so far.
4. Return `dummy.next`.

## Code
- [Solution.py](./Solution.py)
- [Solution.cpp](./Solution.cpp)
- [Solution.java](./Solution.java)

## Line-by-Line Explanation
- `prev` only ever advances onto a node once we've confirmed it isn't the start of a
  duplicate run — so `prev.next` is always safe to treat as "next confirmed-unique
  node" once the duplicate-skipping inner loop finishes.
- The inner `while current and current.val == val` loop consumes the *entire* run
  (which could be longer than 2, e.g. three or more identical values), not just one
  pair.

## Dry Run
`head = 1->2->3->3->4->4->5`

- current=1: next=2, different → prev=1, current=2.
- current=2: next=3, different → prev=2, current=3.
- current=3: next=3, same! val=3. Skip while val==3 → current lands on 4 (first).
  prev(2).next = 4. (3,3 excised)
- current=4: next=4, same! val=4. Skip → current lands on 5. prev(2).next = 5.
  (4,4 excised)
- current=5: next=None → prev=5, current=None.

Result: `1->2->5`.

## Complexity
- Time: O(n) — each node visited a constant number of times.
- Space: O(1)

## Edge Cases
- All nodes are duplicates of each other → result is an empty list.
- No duplicates at all → list returned unchanged.
- Duplicate run at the very head → dummy node correctly allows `prev.next` to skip
  past it even before any "confirmed unique" node has been seen.
