# Best Time to Buy and Sell Stock IV

**Difficulty:** Hard | **Category:** Multidimensional DP
**LeetCode:** https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/

## Problem Understanding
Generalize Stock III: maximize profit with **at most `k`** transactions.

## Approach
Generalize the 4-variable rolling state into arrays indexed by transaction number: `buy[i]` / `sell[i]` are the best balance/profit after the i-th buy/sell. Each day, update every transaction level in increasing order, since `buy[i]` depends on `sell[i-1]` from a possibly-earlier day.

## Algorithm
1. `buy[i] = -infinity` for all i initially (unreachable), `sell[0] = 0` (zero transactions, zero profit).
2. For each price, for `i` from 1 to `k`: `buy[i] = max(buy[i], sell[i-1] - price)`; `sell[i] = max(sell[i], buy[i] + price)`.
3. Return `sell[k]`.

## Code
- [Solution.py](./Solution.py)
- [Solution.cpp](./Solution.cpp)
- [Solution.java](./Solution.java)

## Dry Run
`k=2`, `prices=[3,2,6,5,0,3]`: works out to the same style of result as Stock III generalized to k=2 → best profit `7` (buy@2 sell@6, buy@0 sell@3).

## Complexity
- Time: O(n × k)
- Space: O(k)

## Edge Cases
- `k = 0` → 0 profit, no transactions allowed.
- `k` large enough to exceed `n/2` → behaves like the unlimited-transactions variant (every profitable up-move gets captured).
