from collections import deque

class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: list[str]) -> int:
        words = set(wordList)
        if endWord not in words:
            return 0
        q = deque([(beginWord, 1)])
        seen = {beginWord}
        while q:
            word, dist = q.popleft()
            if word == endWord:
                return dist
            for i in range(len(word)):
                for ch in 'abcdefghijklmnopqrstuvwxyz':
                    nxt = word[:i] + ch + word[i + 1:]
                    if nxt in words and nxt not in seen:
                        seen.add(nxt)
                        q.append((nxt, dist + 1))
        return 0
