import java.util.*;

class Solution {
    private List<List<Integer>> res = new ArrayList<>();
    private List<Integer> path = new ArrayList<>();

    public List<List<Integer>> combine(int n, int k) {
        res = new ArrayList<>();
        path = new ArrayList<>();
        bt(1, n, k);
        return res;
    }

    private void bt(int start, int n, int k) {
        if (path.size() == k) {
            res.add(new ArrayList<>(path));
            return;
        }
        for (int i = start; i <= n - (k - path.size()) + 1; i++) {
            path.add(i);
            bt(i + 1, n, k);
            path.remove(path.size() - 1);
        }
    }
}
