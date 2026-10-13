class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int rows = obstacleGrid.size(), cols = obstacleGrid[0].size();
        vector<long> dp(cols, 0);
        dp[0] = 1;
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (obstacleGrid[r][c] == 1) dp[c] = 0;
                else if (c > 0) dp[c] += dp[c - 1];
            }
        }
        return (int)dp[cols - 1];
    }
};
