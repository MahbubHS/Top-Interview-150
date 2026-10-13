# Evaluate Division

**Difficulty:** Medium | **Category:** Graph General
**LeetCode:** https://leetcode.com/problems/evaluate-division/

## Problem Understanding
Given equations like `a / b = 2.0`, answer queries `x / y`, returning `-1.0` when the answer cannot be determined.

## Approach
Model variables as graph nodes: an equation `a / b = v` is an edge `a → b` with weight `v` and a reverse edge `b → a` with weight `1/v`. A query `x / y` is the product of weights along any path from `x` to `y`, found with DFS (tracking visited nodes).

## Algorithm
1. Build a weighted adjacency map with both directions for each equation.
2. For a query, return `-1.0` if either variable is unknown, `1.0` if they are the same known variable.
3. DFS from `src`; multiply the edge weight by the result of the recursive call; return `-1.0` if no path.

## Code
- [Solution.py](./Solution.py)
- [Solution.cpp](./Solution.cpp)
- [Solution.java](./Solution.java)

## Dry Run
`a/b=2`, `b/c=3`, query `a/c`: path a→b→c gives `2 × 3 = 6`; query `b/a` uses the reverse edge → `0.5`.

## Complexity
- Time: O(Q × (V + E))
- Space: O(V + E)

## Edge Cases
- Unknown variable in a query → `-1.0`.
- `x / x` for a known `x` → `1.0`; for an unknown `x` → `-1.0`.
