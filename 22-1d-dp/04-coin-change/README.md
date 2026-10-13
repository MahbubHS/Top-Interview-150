# Coin Change

**Difficulty:** Medium | **Category:** 1D DP
**LeetCode:** https://leetcode.com/problems/coin-change/

## Problem Understanding
Given coin denominations and a target amount, find the fewest coins needed to make that amount exactly (unlimited supply of each coin), or -1 if impossible.

## Approach
`dp[a]` = minimum coins to make amount `a`. For each amount, try using one of each coin last: `dp[a] = min over coins c of dp[a-c] + 1`. This is bottom-up (unbounded knapsack style) DP, building up from `dp[0] = 0`.

## Algorithm
1. `dp[0] = 0`; all other `dp[a]` start at infinity (unreachable).
2. For each amount `a` from 1 to `amount`: for each coin `c <= a` with `dp[a-c]` reachable, update `dp[a] = min(dp[a], dp[a-c]+1)`.
3. Return `dp[amount]`, or -1 if it stayed infinity.

## Code
- [Solution.py](./Solution.py)
- [Solution.cpp](./Solution.cpp)
- [Solution.java](./Solution.java)

## Dry Run
`coins=[1,2,5]`, amount=11: dp builds up to `dp[11] = 3` (5+5+1).

## Complexity
- Time: O(amount × number of coins)
- Space: O(amount)

## Edge Cases
- `amount = 0` → 0 coins needed.
- No combination reaches the amount (e.g. `coins=[2]`, amount=3) → -1.
