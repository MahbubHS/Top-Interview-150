# Pow(x, n)

**Difficulty:** Medium | **Category:** Math
**LeetCode:** https://leetcode.com/problems/powx-n/

## Problem Understanding
Implement `x^n` for a double base and integer exponent (which may be negative) in better than O(n) time.

## Approach
**Fast exponentiation (binary exponentiation).** Express `n` in binary: `x^n` is the product of `x^(2^k)` for every bit `k` that is set in `n`. Repeatedly square `x` (doubling the exponent it represents) while scanning `n`'s bits from least to most significant, multiplying into the result whenever a bit is 1.

## Algorithm
1. Negative `n`: invert `x` and negate `n` (`x^-n = (1/x)^n`); use a wider type for `n` since `-Integer.MIN_VALUE` overflows a 32-bit int.
2. `result = 1.0`.
3. While `n != 0`: if the lowest bit of `n` is 1, multiply `result` by the current `x`. Square `x`, shift `n` right by 1.
4. Return `result`.

## Code
- [Solution.py](./Solution.py)
- [Solution.cpp](./Solution.cpp)
- [Solution.java](./Solution.java)

## Dry Run
`x=2, n=10` (binary 1010): bit0=0 (skip, x→4), bit1=1 (result=4, x→16), bit2=0 (x→256), bit3=1 (result=4×256=1024). `2^10=1024`. ✓

## Complexity
- Time: O(log |n|)
- Space: O(1)

## Edge Cases
- `n = 0` → `1.0` for any `x` (loop never executes a multiply, result stays 1).
- Negative `n` → handled via the `1/x` inversion.
- `x = 0`, `n > 0` → correctly yields `0.0`.
