# Trapping Rain Water

**Difficulty:** Hard | **Category:** Array / String
**LeetCode:** https://leetcode.com/problems/trapping-rain-water/

## Problem Understanding
Given bar heights forming an elevation map, compute how much water is trapped after
raining.

## Approach
**Two pointers from both ends.** Water trapped above index `i` equals
`min(max_left, max_right) - height[i]`. Instead of precomputing full left/right max
arrays, move whichever pointer has the smaller *known* max inward — that side's water
level is already fully determined (the other side's true max can only help, never hurt,
since it's `>=` the smaller side by construction).

## Algorithm
1. `l=0`, `r=n-1`, `leftMax=rightMax=0`, `water=0`.
2. While `l < r`: compare `height[l]` and `height[r]`.
3. If left is smaller: update `leftMax`, add `leftMax - height[l]` to water, advance `l`.
4. Else: update `rightMax`, add `rightMax - height[r]` to water, retreat `r`.

## Code
See `Solution.py`, `Solution.cpp`, `Solution.java`.

## Line-by-Line Explanation
- Choosing to process the side with the smaller height guarantees the *other* side's
  eventual max is at least as large, so the water level at the processed index is
  correctly bounded by `leftMax` (or `rightMax`) alone.

## Dry Run
`height = [0,1,0,2,1,0,1,3,2,1,2,1]` → known answer `6`.
Pointers converge inward, accumulating water wherever a bar is lower than the running
max on its side; full trace omitted for brevity but follows the rule above at each step.

## Complexity
- Time: O(n) — single pass, pointers move toward each other.
- Space: O(1)

## Edge Cases
- Fewer than 3 bars → no water can be trapped, returns 0.
- Monotonically increasing or decreasing heights → 0 trapped water.
