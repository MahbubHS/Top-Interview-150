import java.util.HashMap;
import java.util.Map;

class Solution {
    public boolean wordPattern(String pattern, String s) {
        String[] words = s.split(" ");
        if (pattern.length() != words.length) return false;

        Map<Character, String> mapPW = new HashMap<>();
        Map<String, Character> mapWP = new HashMap<>();
        for (int i = 0; i < pattern.length(); i++) {
            char ch = pattern.charAt(i);
            String word = words[i];
            if (mapPW.containsKey(ch) && !mapPW.get(ch).equals(word)) return false;
            if (mapWP.containsKey(word) && mapWP.get(word) != ch) return false;
            mapPW.put(ch, word);
            mapWP.put(word, ch);
        }
        return true;
    }
}
