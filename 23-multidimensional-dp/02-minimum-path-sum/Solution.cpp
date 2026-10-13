class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        vector<long> dp(cols, LONG_MAX / 2);
        dp[0] = 0;
        for (int r = 0; r < rows; r++) {
            dp[0] += grid[r][0];
            for (int c = 1; c < cols; c++) {
                dp[c] = grid[r][c] + min(dp[c], dp[c - 1]);
            }
        }
        return (int)dp[cols - 1];
    }
};
