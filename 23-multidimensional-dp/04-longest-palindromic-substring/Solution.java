class Solution {
    public String longestPalindrome(String s) {
        if (s.isEmpty()) return "";
        int start = 0, end = 0;
        for (int i = 0; i < s.length(); i++) {
            int[] r1 = expand(s, i, i);
            if (r1[1] - r1[0] > end - start) { start = r1[0]; end = r1[1]; }
            int[] r2 = expand(s, i, i + 1);
            if (r2[1] - r2[0] > end - start) { start = r2[0]; end = r2[1]; }
        }
        return s.substring(start, end + 1);
    }

    private int[] expand(String s, int l, int r) {
        while (l >= 0 && r < s.length() && s.charAt(l) == s.charAt(r)) {
            l--;
            r++;
        }
        return new int[]{l + 1, r - 1};
    }
}
