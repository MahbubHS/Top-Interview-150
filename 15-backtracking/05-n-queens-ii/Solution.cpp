class Solution {
    int n;
    vector<bool> cols, d1, d2;

    int bt(int r) {
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
public:
    int totalNQueens(int n) {
        this->n = n;
        cols.assign(n, false);
        d1.assign(2 * n - 1, false);
        d2.assign(2 * n - 1, false);
        return bt(0);
    }
};
