import java.util.HashMap;
import java.util.Map;

class Solution {
    public boolean canConstruct(String ransomNote, String magazine) {
        Map<Character, Integer> magCount = new HashMap<>();
        for (char c : magazine.toCharArray()) magCount.merge(c, 1, Integer::sum);
        for (char c : ransomNote.toCharArray()) {
            int remaining = magCount.getOrDefault(c, 0) - 1;
            if (remaining < 0) return false;
            magCount.put(c, remaining);
        }
        return true;
    }
}
