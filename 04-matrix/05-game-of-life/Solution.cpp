class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int rows = board.size(), cols = board[0].size();
        auto countLiveNeighbors = [&](int r, int c) {
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
        };

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                int liveNeighbors = countLiveNeighbors(r, c);
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
};
