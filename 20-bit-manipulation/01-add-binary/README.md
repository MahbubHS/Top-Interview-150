# Add Binary

**Difficulty:** Easy | **Category:** Bit Manipulation
**LeetCode:** https://leetcode.com/problems/add-binary/

## Problem Understanding
Add two binary strings and return the sum, also as a binary string.

## Approach
Simulate elementary-school addition from the rightmost (least significant) bit, exactly like Add Two Numbers but on string digits with base 2: sum two bits plus carry, the output bit is `total % 2`, the new carry is `total / 2`.

## Algorithm
1. Two pointers from the end of each string; `carry = 0`.
2. While either pointer is still valid or a carry remains: add available bits plus carry, append `total % 2` to the result, update `carry = total // 2`.
3. Reverse the accumulated digits at the end (they were built least-significant-first).

## Code
- [Solution.py](./Solution.py)
- [Solution.cpp](./Solution.cpp)
- [Solution.java](./Solution.java)

## Dry Run
`a="11"`, `b="1"`: bit0: 1+1=2 → digit 0, carry 1. bit1: 1+0+1=2 → digit 0, carry 1. final carry → digit 1. Reversed: `"100"`.

## Complexity
- Time: O(max(len(a), len(b)))
- Space: O(max(len(a), len(b))) for the output

## Edge Cases
- Different-length strings → shorter one treated as exhausted (missing bits contribute 0).
- A final carry produces an extra leading `1`.
