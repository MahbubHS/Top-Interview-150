# Two Sum

**Difficulty:** Easy | **Category:** Hashmap
**LeetCode:** https://leetcode.com/problems/two-sum/

## Problem Understanding
Return the indices of the two numbers in `nums` that add up to `target`. Exactly one
valid answer is guaranteed; the same element can't be used twice.

## Approach
Use a hash map to remember numbers already seen. For each current number, check
whether its complement (`target - num`) is already in the map — if so, we've found
our pair in a single pass.

## Algorithm
1. Create an empty map `seen` (value → index).
2. For each index `i` with value `num`: compute `need = target - num`.
3. If `need` is already in `seen`, return `[seen[need], i]`.
4. Otherwise store `seen[num] = i`.
5. Return `[]` if nothing found (won't happen per constraints).

## Code
See `Solution.py`, `Solution.cpp`, `Solution.java`.

## Line-by-Line Explanation
- Checking for `need` *before* inserting the current number prevents matching a value
  against itself unless it appears twice in the array at different indices (which
  would only happen legitimately if two duplicate values together sum to target).

## Dry Run
`nums = [2,7,11,15]`, `target = 9`

| i | num | need | seen | action |
|---|-----|------|------|--------|
| 0 | 2 | 7 | {} | store 2:0 |
| 1 | 7 | 2 | {2:0} | match! return [0,1] |

## Complexity
- Time: O(n)
- Space: O(n)

## Edge Cases
- Duplicate numbers summing to target (e.g. `[3,3]`, target 6) → works since the first
  3 is stored before the second is checked.
- Negative numbers → works unchanged, map lookups don't depend on sign.
