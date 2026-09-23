# Remove Duplicates from Sorted Array

**Difficulty:** Easy | **Category:** Array / String
**LeetCode:** https://leetcode.com/problems/remove-duplicates-from-sorted-array/

## Problem Understanding
Given a sorted array, remove duplicates in place so each element appears once, and
return the new length `k`. The first `k` slots must hold the unique elements in order.

## Approach
Since the array is sorted, duplicates are always adjacent. Use a slow pointer `k` for
the last unique value written, and a fast pointer `i` scanning forward.

## Algorithm
1. If array is empty, return 0.
2. Set `k = 1` (first element is always unique by itself).
3. For `i` from 1 to n-1: if `nums[i] != nums[k-1]`, write `nums[k] = nums[i]`, `k += 1`.
4. Return `k`.

## Code
See `Solution.py`, `Solution.cpp`, `Solution.java`.

## Line-by-Line Explanation
- `k = 1`: the first element is trivially unique, so it's already "kept" at index 0.
- Comparing `nums[i]` to `nums[k-1]` (the last kept value, not `nums[i-1]`) correctly
  skips runs of duplicates longer than 2.
- Only different values advance `k` and get copied forward.

## Dry Run
`nums = [0,0,1,1,1,2,2,3,3,4]`

| i | nums[i] | nums[k-1] | action | k |
|---|---------|-----------|--------|---|
| 1 | 0 | 0 | skip | 1 |
| 2 | 1 | 0 | write nums[1]=1 | 2 |
| 3 | 1 | 1 | skip | 2 |
| 4 | 1 | 1 | skip | 2 |
| 5 | 2 | 1 | write nums[2]=2 | 3 |
| 6 | 2 | 2 | skip | 3 |
| 7 | 3 | 2 | write nums[3]=3 | 4 |
| 8 | 3 | 3 | skip | 4 |
| 9 | 4 | 3 | write nums[4]=4 | 5 |

Result: `k = 5`, `nums = [0,1,2,3,4,...]`.

## Complexity
- Time: O(n)
- Space: O(1)

## Edge Cases
- Empty array → return 0.
- All identical elements → k = 1.
- No duplicates → k = n, array unchanged.
