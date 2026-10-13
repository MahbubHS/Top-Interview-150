# Add Two Numbers

**Difficulty:** Medium | **Category:** Linked List
**LeetCode:** https://leetcode.com/problems/add-two-numbers/

## Problem Understanding
Two numbers are stored as linked lists with digits in **reverse order** (least
significant digit first). Add the two numbers and return the sum as a linked list in
the same reversed-digit format.

## Approach
Simulate elementary-school addition digit by digit, exactly like adding on paper but
starting from the least significant digit (which conveniently is the head of each
list already). Carry any overflow (`>= 10`) into the next digit.

## Algorithm
1. Use a dummy head node to simplify building the result list.
2. While either list still has nodes, or there's a leftover carry: sum the current
   digits (treating a missing node as 0) plus the carry.
3. The new digit is `total % 10`; the new carry is `total // 10`.
4. Append the new digit node, advance both list pointers (if they exist).
5. Return `dummy.next` (skipping the dummy placeholder).

## Code
- [Solution.py](./Solution.py)
- [Solution.cpp](./Solution.cpp)
- [Solution.java](./Solution.java)

## Line-by-Line Explanation
- The dummy head avoids special-casing "is this the first node of the result?" —
  we always attach to `current.next` and advance `current`.
- The loop condition `l1 or l2 or carry` ensures we keep going even if one list is
  shorter, or if a final carry needs its own new digit (e.g. `5 + 5 = 10`).

## Dry Run
`l1 = 2->4->3` (342), `l2 = 5->6->4` (465) → 342 + 465 = 807

- digit1: 2+5+0=7, carry=0 → node 7
- digit2: 4+6+0=10, carry=1 → node 0
- digit3: 3+4+1=8, carry=0 → node 8

Result: `7->0->8` (807). ✓

## Complexity
- Time: O(max(m, n)) where m, n are the two list lengths.
- Space: O(max(m, n)) for the output list (excluding the trivial dummy node).

## Edge Cases
- Lists of different lengths → missing digits treated as 0 via the ternary checks.
- Final carry produces an extra digit (e.g. `[5] + [5]` → `[0,1]` representing 10).
- One list is empty conceptually (not per constraints, but the loop handles it via
  the `l1 or l2 or carry` condition regardless).
