# Roman to Integer

**Difficulty:** Easy | **Category:** Array / String
**LeetCode:** https://leetcode.com/problems/roman-to-integer/

## Problem Understanding
Convert a Roman numeral string to its integer value. Roman numerals are usually
additive, but a smaller symbol before a larger one means subtraction (e.g. `IV` = 4).

## Approach
Scan left to right. If the current symbol's value is less than the *next* symbol's
value, it's a subtractive pair — subtract it. Otherwise add it normally.

## Algorithm
1. Build a value map for the 7 Roman symbols.
2. For each position `i`, compare `value(s[i])` to `value(s[i+1])` (if it exists).
3. Subtract if smaller-before-larger, otherwise add.
4. Return the running total.

## Code
See `Solution.py`, `Solution.cpp`, `Solution.java`.

## Line-by-Line Explanation
- The lookahead comparison handles all six subtractive cases (`IV, IX, XL, XC, CD, CM`)
  uniformly without hardcoding each pair.

## Dry Run
`s = "MCMXCIV"`

| i | symbol | next | subtract? | contribution | total |
|---|--------|------|-----------|---------------|-------|
| 0 | M(1000)| C(100) | no | +1000 | 1000 |
| 1 | C(100) | M(1000)| yes | -100 | 900 |
| 2 | M(1000)| X(10) | no | +1000 | 1900 |
| 3 | X(10)  | C(100) | yes | -10 | 1890 |
| 4 | C(100) | I(1) | no | +100 | 1990 |
| 5 | I(1)   | V(5) | yes | -1 | 1989 |
| 6 | V(5)   | - | no | +5 | 1994 |

Result: `1994`.

## Complexity
- Time: O(n)
- Space: O(1) (fixed-size map)

## Edge Cases
- Single-character input (e.g. `"I"`) → returns that symbol's value directly.
- Input assumed valid per constraints, so no malformed-numeral handling needed.
