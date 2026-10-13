# Bitwise AND of Numbers Range

**Difficulty:** Medium | **Category:** Bit Manipulation
**LeetCode:** https://leetcode.com/problems/bitwise-and-of-numbers-range/

## Problem Understanding
Return the bitwise AND of all integers in the inclusive range `[left, right]`.

## Approach
Any bit position where `left` and `right` differ must take **both** 0 and 1 somewhere within the range (since the range is contiguous), so that bit ANDs to 0 across the whole range. The AND of the whole range is therefore exactly the **common binary prefix** shared by `left` and `right`. Find it by right-shifting both until they become equal, counting the shifts, then shifting back.

## Algorithm
1. `shift = 0`.
2. While `left < right`: shift both right by 1 (drop their lowest differing bits), increment `shift`.
3. Once equal, that value is the shared prefix — shift it back left by `shift` to restore the trailing zero bits.

## Code
- [Solution.py](./Solution.py)
- [Solution.cpp](./Solution.cpp)
- [Solution.java](./Solution.java)

## Dry Run
`left=5 (101)`, `right=7 (111)`: shift once → 2,3 (10,11) still differ; shift again → 1,1 equal, shift=2. Result = `1 << 2 = 4 (100)`.

## Complexity
- Time: O(log(right)) — bounded by the bit width
- Space: O(1)

## Edge Cases
- `left == right` → loop never runs, returns `left` unchanged.
- `left = 0` → result is always 0 (shifting 0 keeps it 0).
