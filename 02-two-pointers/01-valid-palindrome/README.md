# Valid Palindrome

**Difficulty:** Easy | **Category:** Two Pointers
**LeetCode:** https://leetcode.com/problems/valid-palindrome/

## Problem Understanding
Check whether a string is a palindrome after lowercasing and removing all
non-alphanumeric characters.

## Approach
Two pointers from both ends, skipping non-alphanumeric characters as we go, comparing
lowercase versions of the letters we land on.

## Algorithm
1. `l = 0`, `r = len(s)-1`.
2. While `l < r`: advance `l` past non-alphanumeric chars; retreat `r` past
   non-alphanumeric chars.
3. Compare `s[l].lower()` to `s[r].lower()`; if different, return False.
4. Move both pointers inward and repeat.
5. If the loop completes, return True.

## Code
See `Solution.py`, `Solution.cpp`, `Solution.java`.

## Line-by-Line Explanation
- The two inner `while` loops are what let us ignore punctuation/spaces without
  building a cleaned copy of the string first — saves O(n) extra space.
- `l < r` guards inside the skip-loops prevent the pointers from crossing while
  skipping.

## Dry Run
`s = "A man, a plan, a canal: Panama"`

Skipping non-alphanumerics and comparing lowercase letters from both ends:
a↔a, m↔m, a↔a, n↔n, a↔a, p↔p, l↔l, a↔a, n↔n, a↔a, c↔c, a↔a, n↔n, a↔a, l↔l — all match.
Result: `True`.

## Complexity
- Time: O(n)
- Space: O(1)

## Edge Cases
- Empty string → trivially True (`l >= r` immediately).
- String with no alphanumeric characters at all → True (nothing to compare).
