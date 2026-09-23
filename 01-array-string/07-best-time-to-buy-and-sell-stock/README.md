# Best Time to Buy and Sell Stock

**Difficulty:** Easy | **Category:** Array / String
**LeetCode:** https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

## Problem Understanding
One transaction allowed (one buy, one later sell). Return the maximum profit, or 0 if
no profit is possible.

## Approach
Track the lowest price seen so far while scanning left to right; at each day, the best
possible profit if selling *today* is `price - min_so_far`. Keep the running maximum.

## Algorithm
1. `min_price = +infinity`, `max_profit = 0`.
2. For each price: update `min_price = min(min_price, price)`.
3. Update `max_profit = max(max_profit, price - min_price)`.
4. Return `max_profit`.

## Code
See `Solution.py`, `Solution.cpp`, `Solution.java`.

## Line-by-Line Explanation
- `min_price` always represents the cheapest buy opportunity available up to the
  current day (never a future day, since we scan forward).
- `price - min_price` is the profit from buying at the historical low and selling today.

## Dry Run
`prices = [7,1,5,3,6,4]`

| price | min_price | profit today | max_profit |
|-------|-----------|--------------|------------|
| 7 | 7 | 0 | 0 |
| 1 | 1 | 0 | 0 |
| 5 | 1 | 4 | 4 |
| 3 | 1 | 2 | 4 |
| 6 | 1 | 5 | 5 |
| 4 | 1 | 3 | 5 |

Result: `5` (buy at 1, sell at 6).

## Complexity
- Time: O(n)
- Space: O(1)

## Edge Cases
- Prices strictly decreasing → profit stays 0.
- Single price → no transaction possible, profit 0.
