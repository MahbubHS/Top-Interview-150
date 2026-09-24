import java.util.*;

class Solution {
    public List<Integer> findSubstring(String s, String[] words) {
        List<Integer> res = new ArrayList<>();
        if (words.length == 0 || s.isEmpty()) return res;
        int wordLen = words[0].length();
        int numWords = words.length;
        int totalLen = wordLen * numWords;
        int n = s.length();
        if (n < totalLen) return res;

        Map<String,Integer> wordCount = new HashMap<>();
        for (String w : words) wordCount.merge(w, 1, Integer::sum);

        for (int offset = 0; offset < wordLen; offset++) {
            int left = offset, count = 0;
            Map<String,Integer> window = new HashMap<>();
            for (int right = offset; right + wordLen <= n; right += wordLen) {
                String word = s.substring(right, right + wordLen);
                if (wordCount.containsKey(word)) {
                    window.merge(word, 1, Integer::sum);
                    count++;
                    while (window.get(word) > wordCount.get(word)) {
                        String leftWord = s.substring(left, left + wordLen);
                        window.merge(leftWord, -1, Integer::sum);
                        left += wordLen;
                        count--;
                    }
                    if (count == numWords) {
                        res.add(left);
                        String leftWord = s.substring(left, left + wordLen);
                        window.merge(leftWord, -1, Integer::sum);
                        left += wordLen;
                        count--;
                    }
                } else {
                    window.clear();
                    count = 0;
                    left = right + wordLen;
                }
            }
        }
        return res;
    }
}
