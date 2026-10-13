import java.util.*;

class Solution {
    private List<String> res = new ArrayList<>();

    public List<String> generateParenthesis(int n) {
        res = new ArrayList<>();
        bt(0, 0, n, new StringBuilder());
        return res;
    }

    private void bt(int open, int close, int n, StringBuilder path) {
        if (path.length() == 2 * n) {
            res.add(path.toString());
            return;
        }
        if (open < n) {
            path.append('(');
            bt(open + 1, close, n, path);
            path.deleteCharAt(path.length() - 1);
        }
        if (close < open) {
            path.append(')');
            bt(open, close + 1, n, path);
            path.deleteCharAt(path.length() - 1);
        }
    }
}
