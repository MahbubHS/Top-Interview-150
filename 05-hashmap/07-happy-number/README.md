# Happy Number

**Difficulty:** Easy | **Category:** Hashmap
**LeetCode:** https://leetcode.com/problems/happy-number/

## Problem Understanding
Repeatedly replace `n` with the sum of the squares of its digits. If this process
reaches 1, `n` is "happy." If it loops forever (enters a cycle that never hits 1),
`n` is not happy.

## Approach
Use a hash set to detect cycles: keep transforming `n` and recording each value seen.
If we ever see 1, it's happy. If we ever see a value we've already visited before
reaching 1, we're in a cycle and it will never reach 1.

## Algorithm
1. `seen = {}`.
2. While `n != 1` and `n` not in `seen`: add `n` to `seen`, replace `n` with the sum
   of squares of its digits.
3. Return whether `n == 1`.

## Code
See `Solution.py`, `Solution.cpp`, `Solution.java`.

## Line-by-Line Explanation
- `next_val` extracts digits one at a time via `% 10` and `// 10`, squaring and
  accumulating each.
- The `seen` set is what turns a potentially infinite loop into a guaranteed-terminate
  process: since the digit-square-sum function has a bounded range for any starting
  n, a cycle is mathematically guaranteed if 1 is never reached.

## Dry Run
`n = 19`

19 → 1²+9²=82 → 8²+2²=68 → 6²+8²=100 → 1²+0²+0²=1 → stop, `n == 1` → `True`.

`n = 2`: 2→4→16→37→58→89→145→42→20→4 (already seen!) → cycle detected → `False`.

## Complexity
- Time: O(log n) per transformation (digit count), with a bounded number of
  transformations before either reaching 1 or a repeat (known cycle facts bound this).
- Space: O(1) effectively — the "seen" set stays small since values shrink quickly.

## Edge Cases
- `n = 1` → immediately happy, loop never runs.
- Single-digit unhappy numbers (e.g. `n = 4`) → correctly detected via the known
  4→16→37→...→4 cycle.
