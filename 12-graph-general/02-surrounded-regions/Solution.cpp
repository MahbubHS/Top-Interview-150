class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int rows = board.size(), cols = board[0].size();
        int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        vector<pair<int,int>> stack;
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                bool border = (r == 0 || r == rows - 1 || c == 0 || c == cols - 1);
                if (border && board[r][c] == 'O') {
                    board[r][c] = 'T';
                    stack.push_back({r, c});
                }
            }
        }
        while (!stack.empty()) {
            auto [x, y] = stack.back();
            stack.pop_back();
            for (auto& d : dirs) {
                int nx = x + d[0], ny = y + d[1];
                if (nx >= 0 && nx < rows && ny >= 0 && ny < cols && board[nx][ny] == 'O') {
                    board[nx][ny] = 'T';
                    stack.push_back({nx, ny});
                }
            }
        }
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (board[r][c] == 'O') board[r][c] = 'X';
                else if (board[r][c] == 'T') board[r][c] = 'O';
            }
        }
    }
};
