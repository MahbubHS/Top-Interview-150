class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        words = s.split()
        if len(pattern) != len(words):
            return False
        map_pw: dict[str, str] = {}
        map_wp: dict[str, str] = {}
        for ch, word in zip(pattern, words):
            if ch in map_pw and map_pw[ch] != word:
                return False
            if word in map_wp and map_wp[word] != ch:
                return False
            map_pw[ch] = word
            map_wp[word] = ch
        return True
