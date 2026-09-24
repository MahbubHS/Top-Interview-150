from collections import defaultdict

class Solution:
    def groupAnagrams(self, strs: list[str]) -> list[list[str]]:
        groups: dict[tuple, list[str]] = defaultdict(list)
        for word in strs:
            key = tuple(sorted(word))
            groups[key].append(word)
        return list(groups.values())
