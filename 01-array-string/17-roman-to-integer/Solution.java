import java.util.HashMap;
import java.util.Map;

class Solution {
    public int romanToInt(String s) {
        Map<Character, Integer> vals = new HashMap<>();
        vals.put('I', 1); vals.put('V', 5); vals.put('X', 10); vals.put('L', 50);
        vals.put('C', 100); vals.put('D', 500); vals.put('M', 1000);
        int total = 0;
        for (int i = 0; i < s.length(); i++) {
            int cur = vals.get(s.charAt(i));
            if (i + 1 < s.length() && cur < vals.get(s.charAt(i + 1))) total -= cur;
            else total += cur;
        }
        return total;
    }
}
