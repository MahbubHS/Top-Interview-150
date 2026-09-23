# Gas Station

**Difficulty:** Medium | **Category:** Array / String
**LeetCode:** https://leetcode.com/problems/gas-station/

## Problem Understanding
`n` gas stations in a circle; `gas[i]` fuel available at station `i`, `cost[i]` fuel
needed to travel from `i` to `i+1`. Find the starting station index that allows a full
circuit, or -1 if impossible (guaranteed at most one valid answer).

## Approach
Two key greedy facts: (1) a solution exists only if `sum(gas) >= sum(cost)`.
(2) If the tank goes negative starting from station `s`, no station between `s` and the
failure point could be a valid start either — so jump the candidate start straight past
the failure point.

## Algorithm
1. Track `total` (overall gas-cost surplus) and `tank` (current running surplus since
   the candidate `start`).
2. For each station, add `gas[i]-cost[i]` to both.
3. If `tank` drops below 0, no station up through `i` can be a valid start — reset
   `start = i+1`, `tank = 0`.
4. If `total >= 0`, `start` is the answer; otherwise -1.

## Code
See `Solution.py`, `Solution.cpp`, `Solution.java`.

## Line-by-Line Explanation
- `total < 0` at the end means there simply isn't enough gas overall — impossible.
- Resetting `tank = 0` whenever it goes negative discards the failed segment and starts
  a fresh candidate window at the next station.

## Dry Run
`gas = [1,2,3,4,5]`, `cost = [3,4,5,1,2]`

| i | diff | total | tank | reset? | start |
|---|------|-------|------|--------|-------|
| 0 | -2 | -2 | -2 | yes | 1 |
| 1 | -2 | -4 | -2 | yes | 2 |
| 2 | -2 | -6 | -2 | yes | 3 |
| 3 | 3 | -3 | 3 | no | 3 |
| 4 | 3 | 0 | 6 | no | 3 |

`total = 0 >= 0` → answer `3`.

## Complexity
- Time: O(n)
- Space: O(1)

## Edge Cases
- `sum(gas) == sum(cost)` exactly → still solvable (answer exists, uses every drop).
- Single station → trivially answer 0 if `gas[0] >= cost[0]`.
