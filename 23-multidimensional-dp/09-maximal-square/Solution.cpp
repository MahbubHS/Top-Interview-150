class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        vector<vector<int>> dp(rows + 1, vector<int>(cols + 1, 0));
        int best = 0;
        for (int r = 1; r <= rows; r++) {
            for (int c = 1; c <= cols; c++) {
                if (matrix[r - 1][c - 1] == '1') {
                    dp[r][c] = 1 + min({dp[r - 1][c], dp[r][c - 1], dp[r - 1][c - 1]});
                    best = max(best, dp[r][c]);
                }
            }
        }
        return best * best;
    }
};
