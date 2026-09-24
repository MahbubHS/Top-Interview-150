# Two Sum II - Input Array Is Sorted

**Difficulty:** Medium | **Category:** Two Pointers
**LeetCode:** https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

## Problem Understanding
Given a **sorted** array, find the two (1-indexed) positions whose values sum exactly
to `target`. Exactly one solution is guaranteed.

## Approach
Because the array is sorted, two pointers from both ends work directly: if the current
sum is too small, the only way to increase it is to move the left pointer right; if
too large, move the right pointer left.

## Algorithm
1. `l = 0`, `r = n-1`.
2. While `l < r`: compute `sum = numbers[l] + numbers[r]`.
3. If `sum == target`, return `[l+1, r+1]` (1-indexed).
4. If `sum < target`, `l += 1`; else `r -= 1`.

## Code
See `Solution.py`, `Solution.cpp`, `Solution.java`.

## Line-by-Line Explanation
- Sortedness is what guarantees the greedy pointer move is always correct: increasing
  `l` strictly increases the sum, decreasing `r` strictly decreases it, so we never
  need to backtrack.

## Dry Run
`numbers = [2,7,11,15]`, `target = 9`

| l | r | sum | action |
|---|---|-----|--------|
| 0 | 3 | 2+15=17 | too big, r-- |
| 0 | 2 | 2+11=13 | too big, r-- |
| 0 | 1 | 2+7=9 | match! |

Result: `[1, 2]`.

## Complexity
- Time: O(n)
- Space: O(1)

## Edge Cases
- Smallest possible array (length 2) → immediately checked and returned.
- Negative numbers present → algorithm works unchanged since it only relies on sort
  order, not positivity.
