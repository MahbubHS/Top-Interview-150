class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows == 1:
            return s
        rows = [''] * numRows
        cur, step = 0, 1
        for c in s:
            rows[cur] += c
            if cur == 0:
                step = 1
            elif cur == numRows - 1:
                step = -1
            cur += step
        return ''.join(rows)
