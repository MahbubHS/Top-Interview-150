# Majority Element

**Difficulty:** Easy | **Category:** Array / String
**LeetCode:** https://leetcode.com/problems/majority-element/

## Problem Understanding
Find the element that appears more than `n/2` times in the array. It is guaranteed
such an element always exists.

## Approach
**Boyer-Moore Voting Algorithm.** Maintain a `candidate` and a `count`. Treat matches
as +1 votes and mismatches as -1 votes; when `count` hits 0, switch candidates. Because
the majority element outnumbers all others combined, it always survives as the final
candidate.

## Algorithm
1. `count = 0`, `candidate = None`.
2. For each `num`: if `count == 0`, set `candidate = num`.
3. Increment `count` if `num == candidate`, else decrement.
4. Return `candidate` at the end.

## Code
See `Solution.py`, `Solution.cpp`, `Solution.java`.

## Line-by-Line Explanation
- `count == 0` triggers a "reset" — we adopt a fresh candidate whenever the running
  tally cancels out.
- The `+1 / -1` scheme means non-majority elements can at most cancel out an equal
  number of majority votes, never outlast them.

## Dry Run
`nums = [2,2,1,1,1,2,2]`

| num | count before | candidate | count after |
|-----|--------------|-----------|-------------|
| 2 | 0 | 2 | 1 |
| 2 | 1 | 2 | 2 |
| 1 | 2 | 2 | 1 |
| 1 | 1 | 2 | 0 |
| 1 | 0 | 1 | 1 |
| 2 | 1 | 1 | 0 |
| 2 | 0 | 2 | 1 |

Result: `2`.

## Complexity
- Time: O(n)
- Space: O(1)

## Edge Cases
- Single-element array → that element is trivially the majority.
- Majority element exactly at the boundary (`n/2 + 1` occurrences) → still works.
