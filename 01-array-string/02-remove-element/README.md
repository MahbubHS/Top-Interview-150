# Remove Element

**Difficulty:** Easy | **Category:** Array / String
**LeetCode:** https://leetcode.com/problems/remove-element/

## Problem Understanding
Remove every occurrence of `val` from `nums` in place and return the new length `k`.
The first `k` elements of `nums` must hold the remaining values, in any order.

## Approach
Classic **write-pointer** technique: walk the array with a read pointer `i`; whenever
the current value is not `val`, copy it to the write pointer `k` and advance `k`.

## Algorithm
1. Initialize `k = 0`.
2. For each `i` from `0` to `n-1`: if `nums[i] != val`, set `nums[k] = nums[i]`, `k += 1`.
3. Return `k`.

## Code
See `Solution.py`, `Solution.cpp`, `Solution.java`.

## Line-by-Line Explanation
- `k`: tracks how many "keep" elements have been written so far — becomes the answer.
- The loop reads every element once; elements equal to `val` are simply skipped (not copied).
- Writing to `nums[k]` while reading `nums[i]` (`k <= i` always) never overwrites unread data.

## Dry Run
`nums = [3,2,2,3]`, `val = 3`

| i | nums[i] | keep? | k after |
|---|---------|-------|---------|
| 0 | 3 | no  | 0 |
| 1 | 2 | yes | 1 (nums[0]=2) |
| 2 | 2 | yes | 2 (nums[1]=2) |
| 3 | 3 | no  | 2 |

Result: `k = 2`, `nums = [2,2,_,_]`.

## Complexity
- Time: O(n)
- Space: O(1)

## Edge Cases
- Empty array → returns 0 immediately.
- All elements equal `val` → returns 0.
- No elements equal `val` → array unchanged, returns n.
