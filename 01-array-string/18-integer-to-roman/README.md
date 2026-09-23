# Integer to Roman

**Difficulty:** Medium | **Category:** Array / String
**LeetCode:** https://leetcode.com/problems/integer-to-roman/

## Problem Understanding
Convert an integer (1-3999) to its Roman numeral representation.

## Approach
**Greedy symbol table.** List every value/symbol pair — including the six subtractive
combinations (`CM, CD, XC, XL, IX, IV`) — from largest to smallest. Repeatedly subtract
the largest value that still fits and append its symbol.

## Algorithm
1. Build the ordered value/symbol list (largest first).
2. For each pair `(v, sym)`, while `num >= v`, append `sym` and subtract `v`.
3. Return the concatenated result.

## Code
See `Solution.py`, `Solution.cpp`, `Solution.java`.

## Line-by-Line Explanation
- Including `CM/CD/XC/XL/IX/IV` as first-class entries avoids any special-casing —
  the greedy loop naturally picks them whenever appropriate because they're checked
  before their component symbols.

## Dry Run
`num = 1994`

| v,sym | num before | appended | num after |
|-------|-----------|----------|-----------|
| 1000,M | 1994 | M | 994 |
| 900,CM | 994 | CM | 94 |
| 90,XC | 94 | XC | 4 |
| 4,IV | 4 | IV | 0 |

Result: `"MCMXCIV"`.

## Complexity
- Time: O(1) — at most ~15 symbols appended regardless of input size (bounded by
  constraints), though commonly expressed as O(log(num)).
- Space: O(1) extra (excluding the output string).

## Edge Cases
- `num = 1` → `"I"`.
- `num = 3999` (max per constraints) → `"MMMCMXCIX"`.
