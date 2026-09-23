# Candy

**Difficulty:** Hard | **Category:** Array / String
**LeetCode:** https://leetcode.com/problems/candy/

## Problem Understanding
Each child gets at least 1 candy; a child with a higher rating than an immediate
neighbor must get strictly more candy than that neighbor. Minimize total candies.

## Approach
**Two-pass greedy.** The constraint has two independent directions (compare with left
neighbor, compare with right neighbor), so satisfy them one at a time and take the max.
- Left-to-right pass: enforce "higher rating than left neighbor → more candy than left."
- Right-to-left pass: enforce "higher rating than right neighbor → more candy than
  right," without breaking what pass 1 already guaranteed (hence the `max`).

## Algorithm
1. Initialize all candies to 1.
2. Left-to-right: if `ratings[i] > ratings[i-1]`, set `candies[i] = candies[i-1] + 1`.
3. Right-to-left: if `ratings[i] > ratings[i+1]`, set
   `candies[i] = max(candies[i], candies[i+1] + 1)`.
4. Sum and return.

## Code
See `Solution.py`, `Solution.cpp`, `Solution.java`.

## Line-by-Line Explanation
- The `max` in the second pass is essential: it preserves any larger value already
  earned from the left-neighbor comparison instead of overwriting it.

## Dry Run
`ratings = [1,0,2]`

Left pass: `[1,1,2]` (index 2: 2>0 → 1+1=2)
Right pass: index 1: `ratings[1]=0`, not `>ratings[2]=2` → unchanged.
index 0: `ratings[0]=1 > ratings[1]=0` → `candies[0]=max(1, candies[1]+1=2)=2`.
Final: `[2,1,2]`, sum = `5`.

## Complexity
- Time: O(n)
- Space: O(n) for the candies array.

## Edge Cases
- All equal ratings → every child gets exactly 1 candy.
- Strictly increasing ratings → candies form `1,2,3,...,n`.
- Strictly decreasing ratings → candies form `n,n-1,...,1`.
