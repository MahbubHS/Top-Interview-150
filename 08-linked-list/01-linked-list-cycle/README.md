# Linked List Cycle

**Difficulty:** Easy | **Category:** Linked List
**LeetCode:** https://leetcode.com/problems/linked-list-cycle/

## Problem Understanding
Determine whether a linked list has a cycle (some node's `next` eventually points back
to an earlier node), using O(1) extra space.

## Approach
**Floyd's Tortoise and Hare.** Move two pointers through the list at different
speeds — `slow` one step at a time, `fast` two steps at a time. If there's no cycle,
`fast` reaches the end first. If there IS a cycle, `fast` eventually laps `slow` from
behind and they meet at the same node.

## Algorithm
1. `slow = fast = head`.
2. While `fast` and `fast.next` are both non-null: advance `slow` by 1, `fast` by 2.
3. If `slow == fast` at any point, a cycle exists → return True.
4. If the loop ends naturally (fast hit the end), return False.

## Code
- [Solution.py](./Solution.py)
- [Solution.cpp](./Solution.cpp)
- [Solution.java](./Solution.java)

## Line-by-Line Explanation
- The `while` condition checks both `fast` and `fast.next` to avoid a null-pointer
  dereference when computing `fast.next.next`.
- `fast` gains exactly one extra step on `slow` every iteration; in a cycle of length
  L, the gap (mod L) cycles through every value including 0, guaranteeing a meeting.

## Dry Run
List: `3 -> 2 -> 0 -> -4 -> (back to 2)`

slow and fast both start at 3. Step 1: slow=2, fast=0. Step 2: slow=0, fast=2 (via
-4->2). Step 3: slow=-4, fast=-4 → **match!** → `True`.

## Complexity
- Time: O(n) — fast pointer traverses at most twice the list length before either
  finishing or meeting slow.
- Space: O(1)

## Edge Cases
- Empty list (`head = None`) → loop never runs, returns False.
- Single node with no self-loop → `fast.next` is null immediately, returns False.
- Single node that points to itself → slow=fast=that node's next step, they meet
  immediately, returns True.
