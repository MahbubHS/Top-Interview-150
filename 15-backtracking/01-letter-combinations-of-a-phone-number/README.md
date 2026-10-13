# Letter Combinations of a Phone Number

**Difficulty:** Medium | **Category:** Backtracking
**LeetCode:** https://leetcode.com/problems/letter-combinations-of-a-phone-number/

## Problem Understanding
Given a string of digits 2-9, return every letter combination they could represent on a phone keypad.

## Approach
Each digit is a choice among its letters, and the choices multiply. Build combinations one digit at a time with **backtracking**: append a letter, recurse to the next digit, then remove the letter and try the next one.

## Algorithm
1. If `digits` is empty return `[]`.
2. `bt(i, path)`: when `i == len(digits)`, record the path.
3. Otherwise loop over the letters of digit `i`: push, recurse on `i+1`, pop.

## Code
- [Solution.py](./Solution.py)
- [Solution.cpp](./Solution.cpp)
- [Solution.java](./Solution.java)

## Dry Run
`"23"` → `ad, ae, af, bd, be, bf, cd, ce, cf`.

## Complexity
- Time: O(4^n × n) for n digits
- Space: O(n) recursion + output

## Edge Cases
- Empty input → `[]` (not `[""]`).
- Digits 7 and 9 have 4 letters.
