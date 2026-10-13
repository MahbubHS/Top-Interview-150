import java.util.Arrays;

class Solution {
    public int maxProfit(int k, int[] prices) {
        if (prices.length == 0 || k == 0) return 0;
        int[] buy = new int[k + 1];
        int[] sell = new int[k + 1];
        Arrays.fill(buy, Integer.MIN_VALUE);
        for (int p : prices) {
            for (int i = 1; i <= k; i++) {
                buy[i] = Math.max(buy[i], sell[i - 1] - p);
                sell[i] = Math.max(sell[i], buy[i] + p);
            }
        }
        return sell[k];
    }
}
