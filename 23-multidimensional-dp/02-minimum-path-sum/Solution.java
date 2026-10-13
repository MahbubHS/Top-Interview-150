class Solution {
    public int minPathSum(int[][] grid) {
        int rows = grid.length, cols = grid[0].length;
        int[] dp = new int[cols];
        java.util.Arrays.fill(dp, Integer.MAX_VALUE / 2);
        dp[0] = 0;
        for (int r = 0; r < rows; r++) {
            dp[0] += grid[r][0];
            for (int c = 1; c < cols; c++) {
                dp[c] = grid[r][c] + Math.min(dp[c], dp[c - 1]);
            }
        }
        return dp[cols - 1];
    }
}
