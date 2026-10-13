import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class Solution {
    public int[][] merge(int[][] intervals) {
        Arrays.sort(intervals, (a, b) -> a[0] - b[0]);
        List<int[]> res = new ArrayList<>();
        res.add(intervals[0]);
        for (int i = 1; i < intervals.length; i++) {
            int start = intervals[i][0], end = intervals[i][1];
            int[] last = res.get(res.size() - 1);
            if (start <= last[1]) {
                last[1] = Math.max(last[1], end);
            } else {
                res.add(intervals[i]);
            }
        }
        return res.toArray(new int[res.size()][]);
    }
}
