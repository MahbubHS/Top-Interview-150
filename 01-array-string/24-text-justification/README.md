# Text Justification

**Difficulty:** Hard | **Category:** Array / String
**LeetCode:** https://leetcode.com/problems/text-justification/

## Problem Understanding
Given `words` and a target `maxWidth`, pack as many words as possible per line, then
justify: pad spaces so each *full* line's text spans exactly `maxWidth`, distributing
extra spaces as evenly as possible (leftmost gaps get the extras). The last line and
any line with only one word are left-justified instead, padded with trailing spaces.

## Approach
Greedy line-packing plus careful space distribution:
1. Greedily fit as many words as possible on a line without exceeding `maxWidth`
   (accounting for at least one space between each pair).
2. If it's the last line or the line has only one word, left-justify with trailing
   spaces.
3. Otherwise, compute total needed spaces, divide evenly among the gaps between words,
   and give the leftover remainder spaces to the leftmost gaps first.

## Algorithm
1. `idx = 0`; while `idx < n`: find the farthest `last` such that words `idx..last-1`
   fit on one line (character count + one space per gap ≤ maxWidth).
2. If this is the final line or only one word fits: join with single spaces, pad the
   end with spaces to reach `maxWidth`.
3. Otherwise: `totalSpaces = maxWidth - totalChars`, `gaps = numWords - 1`,
   `spaceEach = totalSpaces / gaps`, `extra = totalSpaces % gaps`. Insert `spaceEach`
   spaces after each word, plus one bonus space for the first `extra` gaps.
4. Advance `idx = last` and repeat.

## Code
See `Solution.py`, `Solution.cpp`, `Solution.java`.

## Line-by-Line Explanation
- The inner `while` computing `last` uses `total + word.length + (last-idx)` — the
  `(last-idx)` term accounts for the minimum one space required between each already
  -included word.
- `spaceEach`/`extra` implement "distribute as evenly as possible, extras go left."

## Dry Run
`words = ["This","is","an","example","of","text","justification."]`, `maxWidth = 16`

Line 1 fits `"This","is","an"` (4+2+1+2+1+2=... within 16). 3 words → 2 gaps,
`totalChars = 8`, `totalSpaces = 8`, `spaceEach=4`, `extra=0` →
`"This    is    an"`... (exact spacing per the even-distribution rule) →
`"This    is    an"` trimmed to width 16: `"This    is    an"`.
(See LeetCode's official example for the full 3-line expected output.)

## Complexity
- Time: O(n) where n is total character count across all words.
- Space: O(n) for the output lines.

## Edge Cases
- A single word longer than fits alone on a line is still placed alone and
  left-justified with trailing spaces (per constraints, individual words never exceed
  `maxWidth`).
- Last line always left-justified regardless of word count.
- A line with exactly one word (not the last line) is also left-justified (no gaps to
  distribute spaces into).
