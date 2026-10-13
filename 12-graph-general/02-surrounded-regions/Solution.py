class Solution:
    def solve(self, board: list[list[str]]) -> None:
        rows, cols = len(board), len(board[0])
        stack = []
        for r in range(rows):
            for c in range(cols):
                if (r in (0, rows - 1) or c in (0, cols - 1)) and board[r][c] == 'O':
                    board[r][c] = 'T'
                    stack.append((r, c))
        while stack:
            x, y = stack.pop()
            for dx, dy in ((1, 0), (-1, 0), (0, 1), (0, -1)):
                nx, ny = x + dx, y + dy
                if 0 <= nx < rows and 0 <= ny < cols and board[nx][ny] == 'O':
                    board[nx][ny] = 'T'
                    stack.append((nx, ny))
        for r in range(rows):
            for c in range(cols):
                if board[r][c] == 'O':
                    board[r][c] = 'X'
                elif board[r][c] == 'T':
                    board[r][c] = 'O'
