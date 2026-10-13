class Solution {
    private int n;
    private boolean[] cols, d1, d2;

    public int totalNQueens(int n) {
        this.n = n;
        cols = new boolean[n];
        d1 = new boolean[2 * n - 1];
        d2 = new boolean[2 * n - 1];
        return bt(0);
    }

    private int bt(int r) {
        if (r == n) return 1;
        int total = 0;
        for (int c = 0; c < n; c++) {
            if (cols[c] || d1[r - c + n - 1] || d2[r + c]) continue;
            cols[c] = d1[r - c + n - 1] = d2[r + c] = true;
            total += bt(r + 1);
            cols[c] = d1[r - c + n - 1] = d2[r + c] = false;
        }
        return total;
    }
}
