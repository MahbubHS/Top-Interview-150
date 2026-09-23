class Solution:
    def fullJustify(self, words: list[str], maxWidth: int) -> list[str]:
        res = []
        idx = 0
        n = len(words)
        while idx < n:
            total = len(words[idx])
            last = idx + 1
            while last < n and total + len(words[last]) + (last - idx) <= maxWidth:
                total += len(words[last])
                last += 1

            num_words = last - idx
            if last == n or num_words == 1:
                line = ' '.join(words[idx:last])
                line += ' ' * (maxWidth - len(line))
            else:
                total_spaces = maxWidth - total
                gaps = num_words - 1
                space_each, extra = divmod(total_spaces, gaps)
                parts = []
                for i in range(idx, last - 1):
                    parts.append(words[i])
                    spaces = space_each + (1 if (i - idx) < extra else 0)
                    parts.append(' ' * spaces)
                parts.append(words[last - 1])
                line = ''.join(parts)

            res.append(line)
            idx = last
        return res
