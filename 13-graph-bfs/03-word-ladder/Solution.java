import java.util.*;

class Solution {
    public int ladderLength(String beginWord, String endWord, List<String> wordList) {
        Set<String> words = new HashSet<>(wordList);
        if (!words.contains(endWord)) return 0;
        Deque<String> q = new ArrayDeque<>();
        Map<String, Integer> dist = new HashMap<>();
        q.add(beginWord);
        dist.put(beginWord, 1);
        while (!q.isEmpty()) {
            String word = q.poll();
            int d = dist.get(word);
            if (word.equals(endWord)) return d;
            char[] arr = word.toCharArray();
            for (int i = 0; i < arr.length; i++) {
                char orig = arr[i];
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    if (ch == orig) continue;
                    arr[i] = ch;
                    String cand = new String(arr);
                    if (words.contains(cand) && !dist.containsKey(cand)) {
                        dist.put(cand, d + 1);
                        q.add(cand);
                    }
                }
                arr[i] = orig;
            }
        }
        return 0;
    }
}
