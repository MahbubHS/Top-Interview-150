# Jump Game

**Difficulty:** Medium | **Category:** Array / String
**LeetCode:** https://leetcode.com/problems/jump-game/

## Problem Understanding
`nums[i]` is the max jump length from index `i`. Starting at index 0, determine
whether the last index is reachable.

## Approach
**Greedy farthest-reach.** Track the farthest index reachable so far. If we ever reach
an index beyond that frontier before updating it, we're stuck.

## Algorithm
1. `reach = 0`.
2. For each index `i`: if `i > reach`, index `i` is unreachable → return False.
3. Otherwise update `reach = max(reach, i + nums[i])`.
4. If the loop completes, return True.

## Code
See `Solution.py`, `Solution.cpp`, `Solution.java`.

## Line-by-Line Explanation
- `i > reach` is the failure condition: we walked past the farthest point any earlier
  index could jump to.
- `reach` only grows, representing the best frontier discovered so far.

## Dry Run
`nums = [2,3,1,1,4]`

| i | nums[i] | i>reach? | reach after |
|---|---------|----------|-------------|
| 0 | 2 | no | 2 |
| 1 | 3 | no | 4 |
| 2 | 1 | no | 4 |
| 3 | 1 | no | 4 |
| 4 | 4 | no | 8 |

Loop completes → `True`.

## Complexity
- Time: O(n)
- Space: O(1)

## Edge Cases
- Single-element array → trivially True (already at the last index).
- A `0` early that traps you (e.g. `[3,2,1,0,4]` reaching index 3 with reach=3, then
  stuck) → correctly returns False since `nums[3]=0` can't extend reach past 3 but
  index 4 > reach.
