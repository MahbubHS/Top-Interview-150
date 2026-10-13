# Reverse Bits

**Difficulty:** Easy | **Category:** Bit Manipulation
**LeetCode:** https://leetcode.com/problems/reverse-bits/

## Problem Understanding
Reverse the bits of a 32-bit unsigned integer.

## Approach
Build the result one bit at a time: repeatedly take the lowest bit of `n` and append it as the new lowest bit of a left-shifting accumulator — after 32 iterations the bits have been laid down in reverse order.

## Algorithm
1. `result = 0`.
2. Repeat 32 times: shift `result` left by 1 to make room, OR in `n`'s current lowest bit (`n & 1`), then shift `n` right by 1 to expose its next bit.
3. Return `result`.

## Code
- [Solution.py](./Solution.py)
- [Solution.cpp](./Solution.cpp)
- [Solution.java](./Solution.java)

## Dry Run
`n = 00000010...00` (bit 1 set near the start) → after 32 shift-and-append steps, that single bit ends up at the mirrored position near the end.

## Complexity
- Time: O(1) — always exactly 32 iterations
- Space: O(1)

## Edge Cases
- All-zero input → output is all zero.
- Java uses `>>>` (unsigned shift) so the sign bit doesn't get sign-extended during the shift.
