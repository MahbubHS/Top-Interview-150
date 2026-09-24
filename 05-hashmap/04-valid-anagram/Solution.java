import java.util.HashMap;
import java.util.Map;

class Solution {
    public boolean isAnagram(String s, String t) {
        if (s.length() != t.length()) return false;
        Map<Character, Integer> count = new HashMap<>();
        for (char c : s.toCharArray()) count.merge(c, 1, Integer::sum);
        for (char c : t.toCharArray()) {
            int remaining = count.getOrDefault(c, 0) - 1;
            if (remaining < 0) return false;
            count.put(c, remaining);
        }
        return true;
    }
}
