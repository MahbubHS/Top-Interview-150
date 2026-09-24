# Word Pattern

**Difficulty:** Easy | **Category:** Hashmap
**LeetCode:** https://leetcode.com/problems/word-pattern/

## Problem Understanding
Check whether `s` (space-separated words) follows the same bijective pattern as
`pattern` (individual characters) — the same underlying idea as Isomorphic Strings,
but mapping characters to whole words.

## Approach
Split `s` into words, then apply the same two-way-mapping technique as Isomorphic
Strings: a `pattern-char -> word` map and a `word -> pattern-char` map, both must agree.

## Algorithm
1. Split `s` on whitespace into `words`; if the count differs from `len(pattern)`,
   return False.
2. For each aligned `(ch, word)` pair, enforce consistency in both mapping directions.
3. Return True if the scan completes.

## Code
See `Solution.py`, `Solution.cpp`, `Solution.java`.

## Line-by-Line Explanation
- Splitting first and comparing lengths up front cheaply rejects patterns/strings
  that can't possibly match, before doing any mapping work.
- Exactly the same bidirectional-map logic as Isomorphic Strings, just with `String`
  values instead of `char` values on one side.

## Dry Run
`pattern = "abba"`, `s = "dog cat cat dog"`

- (a,dog): new mapping both ways.
- (b,cat): new mapping both ways.
- (b,cat): matches.
- (a,dog): matches.

Result: `True`.

`pattern = "abba"`, `s = "dog cat cat fish"`: last pair (a,fish) conflicts with
existing map_pw['a']='dog' → `False`.

## Complexity
- Time: O(len(pattern) + len(s))
- Space: O(number of distinct characters/words)

## Edge Cases
- Word count doesn't match pattern length → immediate False.
- Same word appearing for two different pattern characters → caught by the
  `word -> char` map.
