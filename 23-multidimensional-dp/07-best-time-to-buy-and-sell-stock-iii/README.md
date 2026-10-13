# Best Time to Buy and Sell Stock III

**Difficulty:** Hard | **Category:** Multidimensional DP
**LeetCode:** https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/

## Problem Understanding
Maximize profit with **at most two** buy-sell transactions (must sell before buying again).

## Approach
Track four running states, each the best profit achievable so far ending in that state: after a first buy, after a first sell, after a second buy (funded by the first sell's proceeds), after a second sell. Each state updates greedily from the previous day's states — no explicit day-indexed table needed, just 4 rolling values.

## Algorithm
1. `buy1`: best (most negative, i.e. least spent) balance after one buy → `max(buy1, -price)`.
2. `sell1`: best profit after one full transaction → `max(sell1, buy1 + price)`.
3. `buy2`: best balance after buying a second time, funded by `sell1`'s profit → `max(buy2, sell1 - price)`.
4. `sell2`: best profit after two full transactions → `max(sell2, buy2 + price)`.
5. Return `sell2`.

## Code
- [Solution.py](./Solution.py)
- [Solution.cpp](./Solution.cpp)
- [Solution.java](./Solution.java)

## Dry Run
`[3,3,5,0,0,3,1,4]`: the two best transactions are buy@0 sell@3 and buy@1 sell@4 → total profit `6`.

## Complexity
- Time: O(n)
- Space: O(1)

## Edge Cases
- All prices falling → profit stays 0 (every `buyK` stays very negative, `sellK` never improves past 0).
- Fewer than 2 profitable opportunities exist → effectively reduces to the one-transaction answer.
