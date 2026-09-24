class Solution:
    def findSubstring(self, s: str, words: list[str]) -> list[int]:
        if not words or not s:
            return []
        word_len = len(words[0])
        num_words = len(words)
        total_len = word_len * num_words
        n = len(s)
        if n < total_len:
            return []

        word_count: dict[str, int] = {}
        for w in words:
            word_count[w] = word_count.get(w, 0) + 1

        res = []
        for offset in range(word_len):
            left = offset
            count = 0
            window: dict[str, int] = {}
            for right in range(offset, n - word_len + 1, word_len):
                word = s[right:right + word_len]
                if word in word_count:
                    window[word] = window.get(word, 0) + 1
                    count += 1
                    while window[word] > word_count[word]:
                        left_word = s[left:left + word_len]
                        window[left_word] -= 1
                        left += word_len
                        count -= 1
                    if count == num_words:
                        res.append(left)
                        left_word = s[left:left + word_len]
                        window[left_word] -= 1
                        left += word_len
                        count -= 1
                else:
                    window.clear()
                    count = 0
                    left = right + word_len
        return res
