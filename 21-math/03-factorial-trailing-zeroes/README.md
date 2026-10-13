# Factorial Trailing Zeroes

**Difficulty:** Medium | **Category:** Math
**LeetCode:** https://leetcode.com/problems/factorial-trailing-zeroes/

## Problem Understanding
Count the number of trailing zeroes in `n!`, without actually computing the (enormous) factorial.

## Approach
A trailing zero comes from a factor of 10 = 2 × 5. In `n!`, factors of 2 are far more plentiful than factors of 5, so the number of trailing zeroes is exactly the number of times 5 divides into the numbers `1..n` — counted with multiplicity (25 contributes two 5s, 125 contributes three, etc.) via **Legendre's formula**: `⌊n/5⌋ + ⌊n/25⌋ + ⌊n/125⌋ + ...`.

## Algorithm
1. `count = 0`, `power = 5`.
2. While `power <= n`: add `n // power` to `count` (numbers up to n that are multiples of this power of 5), multiply `power` by 5.
3. Return `count`.

## Code
- [Solution.py](./Solution.py)
- [Solution.cpp](./Solution.cpp)
- [Solution.java](./Solution.java)

## Dry Run
`n = 25`: `25/5=5`, `25/25=1`, `25/125=0` (stop) → `5+1 = 6` trailing zeroes in `25!`.

## Complexity
- Time: O(log₅ n)
- Space: O(1)

## Edge Cases
- `n < 5` → 0 trailing zeroes.
- `n = 0` → `0! = 1`, 0 trailing zeroes.
