import java.util.*;

class Solution {
    private static final String[] MAP = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    private List<String> res = new ArrayList<>();

    public List<String> letterCombinations(String digits) {
        res = new ArrayList<>();
        if (digits.isEmpty()) return res;
        bt(digits, 0, new StringBuilder());
        return res;
    }

    private void bt(String digits, int i, StringBuilder path) {
        if (i == digits.length()) {
            res.add(path.toString());
            return;
        }
        for (char ch : MAP[digits.charAt(i) - '0'].toCharArray()) {
            path.append(ch);
            bt(digits, i + 1, path);
            path.deleteCharAt(path.length() - 1);
        }
    }
}
