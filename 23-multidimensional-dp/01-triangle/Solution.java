import java.util.List;

class Solution {
    public int minimumTotal(List<List<Integer>> triangle) {
        int n = triangle.size();
        int[] dp = new int[n];
        List<Integer> last = triangle.get(n - 1);
        for (int i = 0; i < n; i++) dp[i] = last.get(i);
        for (int row = n - 2; row >= 0; row--) {
            List<Integer> cur = triangle.get(row);
            for (int col = 0; col < cur.size(); col++) {
                dp[col] = cur.get(col) + Math.min(dp[col], dp[col + 1]);
            }
        }
        return dp[0];
    }
}
