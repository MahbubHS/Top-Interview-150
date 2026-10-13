# Plus One

**Difficulty:** Easy | **Category:** Math
**LeetCode:** https://leetcode.com/problems/plus-one/

## Problem Understanding
A non-negative integer is given as an array of digits (most significant first). Return the digits of the number plus one.

## Approach
Add 1 like on paper, starting from the last digit. Most of the time this just increments the last digit; only a trailing run of 9s needs carrying, which turns each 9 into a 0 and moves the carry one position left.

## Algorithm
1. Scan from the last digit backward.
2. If a digit is less than 9, incrementing it absorbs the whole carry → update and return immediately.
3. If a digit is 9, it becomes 0 and the carry continues to the next digit left.
4. If every digit was 9, all became 0 and a new leading 1 must be prepended.

## Code
- [Solution.py](./Solution.py)
- [Solution.cpp](./Solution.cpp)
- [Solution.java](./Solution.java)

## Dry Run
`[1,2,3]` → last digit 3<9 → becomes 4 → `[1,2,4]`. `[9,9]` → both become 0, carry survives the whole array → prepend 1 → `[1,0,0]`.

## Complexity
- Time: O(n)
- Space: O(1) extra, or O(n) only in the all-9s case for the new array

## Edge Cases
- All-9s input (e.g. `[9,9,9]`) → result gains a new leading digit.
- Single digit input → simple increment, or `[1,0]` if it was `[9]`.
