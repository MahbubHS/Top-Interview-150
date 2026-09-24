from collections import Counter

class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        note_count = Counter(ransomNote)
        mag_count = Counter(magazine)
        for ch, needed in note_count.items():
            if mag_count[ch] < needed:
                return False
        return True
