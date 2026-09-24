class Solution {
    public void gameOfLife(int[][] board) {
        int rows = board.length, cols = board[0].length;
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                int liveNeighbors = countLiveNeighbors(board, r, c, rows, cols);
                if (board[r][c] == 1 && (liveNeighbors < 2 || liveNeighbors > 3)) {
                    board[r][c] = 2;
                } else if (board[r][c] == 0 && liveNeighbors == 3) {
                    board[r][c] = 3;
                }
            }
        }
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (board[r][c] == 2) board[r][c] = 0;
                else if (board[r][c] == 3) board[r][c] = 1;
            }
        }
    }

    private int countLiveNeighbors(int[][] board, int r, int c, int rows, int cols) {
        int count = 0;
        for (int dr = -1; dr <= 1; dr++) {
            for (int dc = -1; dc <= 1; dc++) {
                if (dr == 0 && dc == 0) continue;
                int nr = r + dr, nc = c + dc;
                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols &&
                    (board[nr][nc] == 1 || board[nr][nc] == 2)) {
                    count++;
                }
            }
        }
        return count;
    }
}
