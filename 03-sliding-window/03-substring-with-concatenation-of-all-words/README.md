# Substring with Concatenation of All Words

**Difficulty:** Hard | **Category:** Sliding Window
**LeetCode:** https://leetcode.com/problems/substring-with-concatenation-of-all-words/

## Problem Understanding
`words` are all the same length. Find every starting index in `s` where a substring is
exactly a concatenation of **all** words in `words`, each used exactly once, in any
order.

## Approach
**Fixed-size-word sliding window, run once per starting offset.** Since every word has
the same length `wordLen`, valid concatenations always align to positions that are
multiples of `wordLen` from some starting offset in `[0, wordLen)`. For each of those
`wordLen` offsets, slide a window word-by-word (not character-by-character), tracking
how many of each needed word are currently in the window with a frequency map, and
shrink from the left whenever a word is over-used or an unrecognized word appears.

## Algorithm
1. Precompute `wordCount`: frequency of each word in `words`.
2. For each `offset` in `0..wordLen-1`:
   - Slide `right` in steps of `wordLen` starting at `offset`.
   - Extract the word at `right`; if it's not a needed word, reset the window entirely
     (`left = right + wordLen`).
   - Otherwise add it to the window's frequency map; while it's over-represented,
     shrink from `left` by one word at a time.
   - If the window now contains exactly `numWords` words, record `left` as a valid
     start, then shrink by one word to keep sliding.

## Code
See `Solution.py`, `Solution.cpp`, `Solution.java`.

## Line-by-Line Explanation
- Running the scan separately for each of the `wordLen` possible alignments
  guarantees every valid starting index gets checked exactly once, since word
  boundaries can only fall on one specific residue class mod `wordLen`.
- The "reset on unknown word" branch is what keeps the window from ever containing a
  word not in `words`.

## Dry Run
`s = "barfoothefoobarman"`, `words = ["foo","bar"]` (`wordLen=3`, `numWords=2`)

At `offset=0`: window sees "bar" (count=1), "foo" (count=2 → matches numWords) →
record `left=0`. Continue: "the" is unknown → reset. Then "foo","bar" → matches →
record `left=9`.

Result: `[0, 9]`.

## Complexity
- Time: O(n * wordLen) roughly — n/wordLen windows across wordLen offsets, each word
  comparison O(wordLen).
- Space: O(numWords * wordLen) for the frequency maps.

## Edge Cases
- `s` shorter than the total concatenation length → return `[]` immediately.
- `words` contains duplicate words → handled correctly since frequency maps (not sets)
  track exact required counts.
