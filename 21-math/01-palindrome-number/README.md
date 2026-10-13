# Palindrome Number

**Difficulty:** Easy | **Category:** Math
**LeetCode:** https://leetcode.com/problems/palindrome-number/

## Problem Understanding
Check whether an integer reads the same forwards and backwards, without converting it to a string.

## Approach
Reverse only the **second half** of the number: keep peeling digits off the end of `x` and building `reverted`, stopping once `reverted` has caught up to (or passed) what remains of `x`. At that point, the two halves can be compared directly.

## Algorithm
1. Negative numbers, and positive numbers ending in 0 (other than 0 itself), can never be palindromes → return False immediately.
2. While `x > reverted`: move the last digit of `x` onto `reverted` (`reverted = reverted*10 + x%10`), then drop it from `x` (`x //= 10`).
3. Even-length numbers end with `x == reverted`; odd-length numbers end with `x == reverted/10` (the extra middle digit in `reverted` is discarded).

## Code
- [Solution.py](./Solution.py)
- [Solution.cpp](./Solution.cpp)
- [Solution.java](./Solution.java)

## Dry Run
`x = 1221`: digits peel off until `x=12, reverted=12` → equal → `True`. `x = 12321`: ends with `x=12, reverted=123` → `x == reverted//10` (12==12) → `True`.

## Complexity
- Time: O(log x) — one pass over half the digits
- Space: O(1)

## Edge Cases
- `x = 0` → palindrome (`True`).
- Negative numbers → always `False`.
- Numbers ending in 0 but not 0 itself (e.g. 10) → always `False` (a leading zero can't appear when reversed).
