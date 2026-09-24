# Isomorphic Strings

**Difficulty:** Easy | **Category:** Hashmap
**LeetCode:** https://leetcode.com/problems/isomorphic-strings/

## Problem Understanding
Check whether the characters in `s` can be consistently replaced to get `t` — a
one-to-one, order-preserving character mapping in **both directions**.

## Approach
Maintain two maps: `s -> t` and `t -> s`. Walk both strings in lockstep. Every
character pairing must agree with any mapping already recorded in *both* directions —
this is what prevents two different source characters from mapping to the same target
character (which would break the "one-to-one" requirement).

## Algorithm
1. If lengths differ, return False.
2. For each aligned pair `(a, b)`: if `a` is already mapped to something other than
   `b`, fail. If `b` is already mapped to something other than `a`, fail.
3. Otherwise record `map_st[a] = b` and `map_ts[b] = a`.
4. Return True if the scan completes.

## Code
See `Solution.py`, `Solution.cpp`, `Solution.java`.

## Line-by-Line Explanation
- The single-direction map alone (`s -> t`) would incorrectly accept cases like
  `s="ab"`, `t="aa"` — both distinct s-characters mapping to the same t-character. The
  reverse map `t -> s` is what catches that.

## Dry Run
`s = "egg"`, `t = "add"`

- (e,a): new mapping both ways.
- (g,d): new mapping both ways.
- (g,d): matches existing mapping.

Result: `True`.

`s = "foo"`, `t = "bar"`: (f,b) ok, (o,a) ok, (o,r): map_st['o']='a' but current b='r'
→ mismatch → `False`.

## Complexity
- Time: O(n)
- Space: O(1) — bounded by character set size.

## Edge Cases
- Equal strings (`s == t`) → trivially isomorphic (identity mapping).
- Single-character strings → always isomorphic.
