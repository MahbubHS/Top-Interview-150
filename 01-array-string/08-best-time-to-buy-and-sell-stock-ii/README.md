# Best Time to Buy and Sell Stock II

**Difficulty:** Medium | **Category:** Array / String
**LeetCode:** https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

## Problem Understanding
Unlimited transactions allowed (but must sell before buying again). Return the maximum
total profit.

## Approach
**Greedy:** capture every upward price move. Summing all positive day-to-day
differences equals the best possible total profit, since any rising run can be split
into consecutive daily buy/sell pairs with the same total gain.

## Algorithm
1. `profit = 0`.
2. For each consecutive pair of days, if price increased, add the difference to profit.
3. Return profit.

## Code
See `Solution.py`, `Solution.cpp`, `Solution.java`.

## Line-by-Line Explanation
- The loop only ever *adds* positive differences — down moves contribute nothing,
  matching the intuition of "skip losing days entirely."

## Dry Run
`prices = [7,1,5,3,6,4]`

| i | diff | profit |
|---|------|--------|
| 1→ | 1-7=-6 | 0 |
| 2 | 5-1=4 | 4 |
| 3 | 3-5=-2 | 4 |
| 4 | 6-3=3 | 7 |
| 5 | 4-6=-2 | 7 |

Result: `7`.

## Complexity
- Time: O(n)
- Space: O(1)

## Edge Cases
- Strictly decreasing prices → profit 0.
- Strictly increasing prices → profit = last - first (equivalent to one big transaction).
