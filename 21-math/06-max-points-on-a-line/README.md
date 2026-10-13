# Max Points on a Line

**Difficulty:** Hard | **Category:** Math
**LeetCode:** https://leetcode.com/problems/max-points-on-a-line/

## Problem Understanding
Given 2D points, find the maximum number of points that lie on the same straight line.

## Approach
Fix each point `i` as a pivot in turn and group every other point `j` by the **reduced-fraction slope** of the line through `i` and `j`. Points sharing the same normalized `(dx, dy)` direction from `i` lie on the same line through `i`; the largest such group (plus the pivot itself) is a candidate answer. Normalizing by the GCD and fixing a sign convention makes equal slopes compare equal regardless of direction or scale.

## Algorithm
1. 0, 1, or 2 points → trivially all collinear, return `n`.
2. For each pivot `i`: compute `(dx, dy)` to every other point `j`, divide both by `gcd(dx, dy)`, and fix a consistent sign (e.g. `dx` non-negative, or `dy` non-negative when `dx == 0`) so opposite directions map to the same key.
3. Count occurrences per normalized slope in a map; the best count plus 1 (for the pivot) is a candidate for the global maximum.

## Code
- [Solution.py](./Solution.py)
- [Solution.cpp](./Solution.cpp)
- [Solution.java](./Solution.java)

## Dry Run
`[[1,1],[2,2],[3,3]]`: pivot (1,1) sees slopes (1,1) to both other points (after reduction) → count 2 + pivot = `3`.

## Complexity
- Time: O(n²) — O(n) pivots × O(n) slope computations each
- Space: O(n) for the slope map per pivot

## Edge Cases
- All points identical → every "slope" is undefined (dx=dy=0); handled by only incrementing a dedicated bucket-free count implicitly via repeated zero keys, still correctly maxing to `n`.
- Vertical line (`dx = 0`) → handled by the GCD/sign normalization without division by zero.
