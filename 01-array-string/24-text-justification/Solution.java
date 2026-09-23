import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<String> fullJustify(String[] words, int maxWidth) {
        List<String> res = new ArrayList<>();
        int idx = 0, n = words.length;
        while (idx < n) {
            int total = words[idx].length(), last = idx + 1;
            while (last < n && total + words[last].length() + (last - idx) <= maxWidth) {
                total += words[last].length();
                last++;
            }
            int numWords = last - idx;
            StringBuilder line = new StringBuilder();
            if (last == n || numWords == 1) {
                for (int i = idx; i < last; i++) {
                    line.append(words[i]);
                    if (i != last - 1) line.append(" ");
                }
                while (line.length() < maxWidth) line.append(" ");
            } else {
                int totalSpaces = maxWidth - total;
                int gaps = numWords - 1;
                int spaceEach = totalSpaces / gaps;
                int extra = totalSpaces % gaps;
                for (int i = idx; i < last - 1; i++) {
                    line.append(words[i]);
                    int spaces = spaceEach + ((i - idx) < extra ? 1 : 0);
                    for (int k = 0; k < spaces; k++) line.append(" ");
                }
                line.append(words[last - 1]);
            }
            res.add(line.toString());
            idx = last;
        }
        return res;
    }
}
