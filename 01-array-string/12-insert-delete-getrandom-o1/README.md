# Insert Delete GetRandom O(1)

**Difficulty:** Medium | **Category:** Array / String
**LeetCode:** https://leetcode.com/problems/insert-delete-getrandom-o1/

## Problem Understanding
Design a data structure supporting `insert(val)`, `remove(val)`, and `getRandom()`
(uniform random existing element) — all in **average O(1)** time.

## Approach
Combine a **dynamic array** (for O(1) random access, needed by `getRandom`) with a
**hash map** from value → its index in the array (for O(1) lookup, needed by `remove`).
The trick for O(1) removal from the middle of an array: swap the target with the last
element, then pop the back.

## Algorithm
- `insert`: if present, fail. Otherwise append to array, record its index in the map.
- `remove`: if absent, fail. Otherwise find its index, overwrite it with the last
  element, update that moved element's index in the map, then shrink the array and
  erase the map entry.
- `getRandom`: pick a uniformly random index into the array.

## Code
See `Solution.py`, `Solution.cpp`, `Solution.java`.

## Line-by-Line Explanation
- `idx` maps value → position, so removal never needs a linear scan.
- The swap-with-last trick avoids an O(n) shift: only two elements' positions ever
  change (the removed one's slot, now holding the old last element).
- `getRandom` relies on the array having no gaps — every slot holds a live element.

## Dry Run
`insert(1)` → vals=[1], idx={1:0}
`insert(2)` → vals=[1,2], idx={1:0,2:1}
`remove(1)` → last=2, vals[0]=2 → vals=[2], idx={2:0}
`getRandom()` → always returns 2 (only element left).

## Complexity
- Time: O(1) average for all three operations.
- Space: O(n) for the array and map.

## Edge Cases
- `remove` on a non-existent value → returns False, no mutation.
- `remove` the only remaining element → array becomes empty.
- `getRandom` when only one element exists → always returns that element.
