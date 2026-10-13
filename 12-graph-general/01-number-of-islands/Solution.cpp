class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size(), cols = grid[0].size(), count = 0;
        int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] != '1') continue;
                count++;
                grid[r][c] = '0';
                vector<pair<int,int>> stack = {{r, c}};
                while (!stack.empty()) {
                    auto [x, y] = stack.back();
                    stack.pop_back();
                    for (auto& d : dirs) {
                        int nx = x + d[0], ny = y + d[1];
                        if (nx >= 0 && nx < rows && ny >= 0 && ny < cols && grid[nx][ny] == '1') {
                            grid[nx][ny] = '0';
                            stack.push_back({nx, ny});
                        }
                    }
                }
            }
        }
        return count;
    }
};
