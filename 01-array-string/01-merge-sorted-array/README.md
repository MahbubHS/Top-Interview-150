# Merge Sorted Array

**Difficulty:** Easy | **Category:** Array / String
**LeetCode:** https://leetcode.com/problems/merge-sorted-array/

## Problem Understanding
`nums1` has length `m + n`, with only the first `m` slots filled and the rest zero-padded.
`nums2` has `n` elements. Merge `nums2` into `nums1` in place so the result is sorted.

## Approach
Merging from the front would overwrite unread values in `nums1`. Instead, fill `nums1`
**from the back**, comparing the largest remaining elements of each array and placing
the bigger one at the end. This never overwrites data we still need.

## Algorithm
1. Set three pointers: `i = m-1` (last real element of `nums1`), `j = n-1` (last of `nums2`),
   `k = m+n-1` (last slot of the merged array).
2. While `j >= 0`: compare `nums1[i]` and `nums2[j]`; place the larger at `nums1[k]`,
   decrement the corresponding pointer and `k`.
3. If `nums1` is exhausted first, the remaining `nums2` elements are already ≤ everything
   placed, and their slots are exactly where they belong — no extra copy step needed
   because the loop condition only checks `j`.

## Code
See `Solution.py`, `Solution.cpp`, `Solution.java`.

## Line-by-Line Explanation
- `i, j, k`: pointers to the last valid element of `nums1`, `nums2`, and the last index
  of the combined array.
- `while j >= 0`: we only need to stop once every element of `nums2` has been placed;
  any leftover `nums1` elements are already in the correct front positions.
- Comparison `nums1[i] > nums2[j]`: picks the larger candidate to go at the back.
- Both branches write to `nums1[k]` then move `k` and the winning pointer backward.

## Dry Run
`nums1 = [1,2,3,0,0,0]`, `m=3`, `nums2 = [2,5,6]`, `n=3`

| i | j | k | Action | nums1 |
|---|---|---|--------|-------|
| 2 | 2 | 5 | 3<6 → take nums2[2]=6 | [1,2,3,0,0,6] |
| 2 | 1 | 4 | 3<5 → take nums2[1]=5 | [1,2,3,0,5,6] |
| 2 | 0 | 3 | 3>2 → take nums1[2]=3 | [1,2,3,3,5,6] |
| 1 | 0 | 2 | 2>2? no → take nums2[0]=2 | [1,2,2,3,5,6] |
| 1 |-1 | - | j<0, stop | [1,2,2,3,5,6] |

## Complexity
- Time: O(m + n) — each element visited once.
- Space: O(1) — in-place merge.

## Edge Cases
- `n == 0`: loop never runs, `nums1` already correct.
- `m == 0`: every element comes straight from `nums2`.
- Duplicate values across arrays: comparison with `>` (not `>=`) keeps merge stable.
