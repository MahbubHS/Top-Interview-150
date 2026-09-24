class Solution:
    def gameOfLife(self, board: list[list[int]]) -> None:
        rows, cols = len(board), len(board[0])

        def count_live_neighbors(r: int, c: int) -> int:
            count = 0
            for dr in (-1, 0, 1):
                for dc in (-1, 0, 1):
                    if dr == 0 and dc == 0:
                        continue
                    nr, nc = r + dr, c + dc
                    if 0 <= nr < rows and 0 <= nc < cols and board[nr][nc] in (1, 2):
                        count += 1
            return count

        # Encode transitions:
        # 2 = was live, now dead
        # 3 = was dead, now live
        for r in range(rows):
            for c in range(cols):
                live_neighbors = count_live_neighbors(r, c)
                if board[r][c] == 1 and (live_neighbors < 2 or live_neighbors > 3):
                    board[r][c] = 2
                elif board[r][c] == 0 and live_neighbors == 3:
                    board[r][c] = 3

        for r in range(rows):
            for c in range(cols):
                if board[r][c] == 2:
                    board[r][c] = 0
                elif board[r][c] == 3:
                    board[r][c] = 1
