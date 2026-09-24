import java.util.HashMap;
import java.util.Map;

class Solution {
    public String minWindow(String s, String t) {
        if (s.isEmpty() || t.isEmpty()) return "";
        Map<Character, Integer> need = new HashMap<>();
        for (char c : t.toCharArray()) need.merge(c, 1, Integer::sum);
        int missing = t.length();
        int l = 0, bestL = 0, bestR = 0;
        for (int r = 1; r <= s.length(); r++) {
            char c = s.charAt(r - 1);
            if (need.getOrDefault(c, 0) > 0) missing--;
            need.put(c, need.getOrDefault(c, 0) - 1);
            if (missing == 0) {
                while (l < r && need.get(s.charAt(l)) < 0) {
                    need.put(s.charAt(l), need.get(s.charAt(l)) + 1);
                    l++;
                }
                if (bestR == 0 || r - l < bestR - bestL) {
                    bestL = l; bestR = r;
                }
                need.put(s.charAt(l), need.get(s.charAt(l)) + 1);
                missing++;
                l++;
            }
        }
        return s.substring(bestL, bestR);
    }
}
