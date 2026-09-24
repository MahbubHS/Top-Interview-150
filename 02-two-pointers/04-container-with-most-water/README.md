# Container With Most Water

**Difficulty:** Medium | **Category:** Two Pointers
**LeetCode:** https://leetcode.com/problems/container-with-most-water/

## Problem Understanding
Given bar heights, choose two lines that, together with the x-axis, form a container
holding the most water. Return the maximum area (width × shorter height).

## Approach
**Two pointers from both ends.** The area is limited by the *shorter* of the two
chosen lines. Starting from the widest possible container (both ends), we can only
improve by moving the pointer at the **shorter** line inward — moving the taller one
inward can only shrink the width without any chance of increasing the limiting height.

## Algorithm
1. `l = 0`, `r = n-1`, `best = 0`.
2. While `l < r`: compute `area = min(height[l], height[r]) * (r - l)`, update `best`.
3. Move the pointer at the shorter line inward.
4. Return `best`.

## Code
See `Solution.py`, `Solution.cpp`, `Solution.java`.

## Line-by-Line Explanation
- `min(height[l], height[r])` is the water level, capped by the shorter wall.
- Moving the shorter side is a provably safe greedy choice: any container using the
  old shorter line's position can never beat the current best once we move past it,
  because width would only decrease while the height cap stays the same or gets worse.

## Dry Run
`height = [1,8,6,2,5,4,8,3,7]`

| l | r | area | move |
|---|---|------|------|
| 0 | 8 | min(1,7)*8=8 | l++ (1<7) |
| 1 | 8 | min(8,7)*7=49 | r-- (7<8) |
| 1 | 7 | min(8,3)*6=18 | r-- |
| 1 | 6 | min(8,8)*5=40 | (tie) r-- |
| ... | | | |

Best found is `49`.

## Complexity
- Time: O(n)
- Space: O(1)

## Edge Cases
- Only two bars → the single possible container is the answer.
- All bars the same height → area is maximized by using the two outermost bars.
