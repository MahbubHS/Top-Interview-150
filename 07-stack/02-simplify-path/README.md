# Simplify Path

**Difficulty:** Medium | **Category:** Stack
**LeetCode:** https://leetcode.com/problems/simplify-path/

## Problem Understanding
Convert a Unix-style absolute path into its canonical simplified form: resolve `.`
(current dir, no-op), `..` (go up one dir), collapse multiple slashes, and drop a
trailing slash.

## Approach
Split the path on `/` and process each segment with a stack: empty segments and `.`
are ignored, `..` pops the stack (go up a directory, if possible), and any real
directory name is pushed. Rejoin the stack with `/` at the end.

## Algorithm
1. Split `path` by `/`.
2. For each segment: skip if empty or `.`; if `..`, pop the stack if non-empty;
   otherwise push the segment.
3. Join the stack with `/`, prefixed by a leading `/`.

## Code
- [Solution.py](./Solution.py)
- [Solution.cpp](./Solution.cpp)
- [Solution.java](./Solution.java)

## Line-by-Line Explanation
- Splitting on `/` automatically handles collapsing multiple consecutive slashes,
  since consecutive slashes just produce empty-string segments, which are skipped.
- Popping only `if stack` (not unconditionally) is what correctly ignores an
  excess `..` at the root (can't go above `/`).

## Dry Run
`path = "/a/./b/../../c/"`

Segments: `["", "a", ".", "b", "..", "..", "c", ""]`
- "" skip, "a" push→[a], "." skip, "b" push→[a,b], ".." pop→[a], ".." pop→[],
  "c" push→[c], "" skip.

Result: `"/c"`.

## Complexity
- Time: O(n) where n is the path length.
- Space: O(n) for the stack/segments.

## Edge Cases
- Root path `"/"` → segments all empty/skip → stack stays empty → returns `"/"`.
- Excess `".."` beyond root (e.g. `"/../"`) → pop on empty stack is a no-op → still
  returns `"/"`.
- Multiple consecutive slashes (e.g. `"/a//b"`) → collapsed automatically.
