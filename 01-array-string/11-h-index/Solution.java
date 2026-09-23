import java.util.Arrays;

class Solution {
    public int hIndex(int[] citations) {
        Arrays.sort(citations);
        int n = citations.length, h = 0;
        for (int i = n - 1; i >= 0; i--) {
            int rank = n - i;
            if (citations[i] >= rank) h = rank;
            else break;
        }
        return h;
    }
}
