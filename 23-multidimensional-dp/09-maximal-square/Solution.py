class Solution:
    def maximalSquare(self, matrix: list[list[str]]) -> int:
        rows, cols = len(matrix), len(matrix[0])
        dp = [[0] * (cols + 1) for _ in range(rows + 1)]
        best = 0
        for r in range(1, rows + 1):
            for c in range(1, cols + 1):
                if matrix[r - 1][c - 1] == '1':
                    dp[r][c] = 1 + min(dp[r - 1][c], dp[r][c - 1], dp[r - 1][c - 1])
                    best = max(best, dp[r][c])
        return best * best
