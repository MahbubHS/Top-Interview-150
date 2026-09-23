# Remove Duplicates from Sorted Array II

**Difficulty:** Medium | **Category:** Array / String
**LeetCode:** https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/

## Problem Understanding
Same as the previous problem, but each value may now appear **at most twice**. Return
the new length after in-place removal of excess duplicates.

## Approach
Generalize the two-pointer trick: only reject `num` if it would make a *third* copy in
a row. Comparing against `nums[k-2]` (two slots back in the *write* region) tells us
exactly that.

## Algorithm
1. `k = 0`.
2. For each `num` in `nums`: if `k < 2` (fewer than 2 elements kept so far) OR
   `num != nums[k-2]` (not a third consecutive duplicate), write it and increment `k`.
3. Return `k`.

## Code
See `Solution.py`, `Solution.cpp`, `Solution.java`.

## Line-by-Line Explanation
- `k < 2`: always allow the first two elements through unconditionally.
- `num != nums[k-2]`: compares the incoming value to the value two positions back in
  the *already-written* prefix — if they match, writing `num` would create a triple.
- This pattern generalizes to "allow at most m duplicates" by comparing to `nums[k-m]`.

## Dry Run
`nums = [1,1,1,2,2,3]`

| num | k | nums[k-2] | keep? | k after |
|-----|---|-----------|-------|---------|
| 1 | 0 | - | yes (k<2) | 1 |
| 1 | 1 | - | yes (k<2) | 2 |
| 1 | 2 | nums[0]=1 | no (equal) | 2 |
| 2 | 2 | nums[0]=1 | yes (2≠1) | 3 |
| 2 | 3 | nums[1]=1 | yes (2≠1) | 4 |
| 3 | 4 | nums[2]=2 | yes (3≠2) | 5 |

Result: `k = 5`, `nums = [1,1,2,2,3]`.

## Complexity
- Time: O(n)
- Space: O(1)

## Edge Cases
- Array length ≤ 2 → nothing to remove, `k = len(nums)`.
- All elements identical → keeps exactly 2.
- Already valid (no value appears 3+ times) → array unchanged.
