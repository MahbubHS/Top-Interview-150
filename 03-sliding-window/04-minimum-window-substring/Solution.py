from collections import Counter

class Solution:
    def minWindow(self, s: str, t: str) -> str:
        if not s or not t:
            return ""
        need = Counter(t)
        missing = len(t)
        l = 0
        best_l, best_r = 0, 0
        for r, c in enumerate(s, 1):
            if need[c] > 0:
                missing -= 1
            need[c] -= 1
            if missing == 0:
                while l < r and need[s[l]] < 0:
                    need[s[l]] += 1
                    l += 1
                if best_r == 0 or r - l < best_r - best_l:
                    best_l, best_r = l, r
                need[s[l]] += 1
                missing += 1
                l += 1
        return s[best_l:best_r]
