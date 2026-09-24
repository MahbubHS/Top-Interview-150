# 3Sum

**Difficulty:** Medium | **Category:** Two Pointers
**LeetCode:** https://leetcode.com/problems/3sum/

## Problem Understanding
Find all unique triplets `[a,b,c]` in the array that sum to zero. No duplicate
triplets in the output.

## Approach
**Sort + fix one element + two pointers.** Sort the array, then for each index `i`
(the smallest of the triplet), use the two-pointer technique on the remaining sorted
subarray to find pairs that sum to `-nums[i]`. Skip duplicate values at every level to
avoid duplicate triplets.

## Algorithm
1. Sort `nums`.
2. For each `i` from 0 to n-1: skip if it's a duplicate of the previous `i`; break
   early if `nums[i] > 0` (can't sum to zero with two non-negative numbers after it).
3. Two pointers `l = i+1`, `r = n-1`: adjust based on whether the 3-sum is too small,
   too large, or exactly zero (in which case record the triplet and skip past
   duplicates on both sides before continuing).

## Code
See `Solution.py`, `Solution.cpp`, `Solution.java`.

## Line-by-Line Explanation
- `if i>0 and nums[i]==nums[i-1]: continue` avoids re-processing the same "anchor"
  value, which would just regenerate triplets already found.
- After recording a match, the inner duplicate-skipping `while` loops prevent emitting
  the same triplet again from adjacent equal values.
- `if nums[i] > 0: break` is a valid early exit since the array is sorted — once the
  anchor is positive, no combination with two later (also non-negative) values can sum
  to zero.

## Dry Run
`nums = [-1,0,1,2,-1,-4]` → sorted: `[-4,-1,-1,0,1,2]`

- i=0 (-4): l=1,r=5 → sums too small mostly, no triplet.
- i=1 (-1): l=2,r=5 → -1+-1+2=0 → triplet `[-1,-1,2]`; continue → -1+0+1=0 → triplet
  `[-1,0,1]`.
- i=2 (-1): duplicate of nums[1], skip.
- i=3 (0): l=4,r=5 → 0+1+2=3, too big, no match.

Result: `[[-1,-1,2],[-1,0,1]]`.

## Complexity
- Time: O(n²) — O(n log n) sort plus O(n) anchors each doing an O(n) two-pointer scan.
- Space: O(1) extra beyond the sort and output (or O(log n)/O(n) depending on sort
  implementation).

## Edge Cases
- Fewer than 3 elements → no triplets possible, return `[]`.
- All zeros → single triplet `[0,0,0]`.
- No triplet sums to zero → return `[]`.
