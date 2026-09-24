class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        last_seen: dict[str, int] = {}
        l = 0
        best = 0
        for r, c in enumerate(s):
            if c in last_seen and last_seen[c] >= l:
                l = last_seen[c] + 1
            last_seen[c] = r
            best = max(best, r - l + 1)
        return best
