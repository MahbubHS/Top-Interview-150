import java.util.HashMap;
import java.util.Map;

class Solution {
    public int maxPoints(int[][] points) {
        int n = points.length;
        if (n <= 2) return n;
        int best = 1;
        for (int i = 0; i < n; i++) {
            Map<Long, Integer> slopes = new HashMap<>();
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                long dx = points[j][0] - points[i][0];
                long dy = points[j][1] - points[i][1];
                long g = gcd(dx, dy);
                if (g != 0) { dx /= g; dy /= g; }
                if (dx < 0 || (dx == 0 && dy < 0)) { dx = -dx; dy = -dy; }
                long key = dx * 200001L + dy;
                int count = slopes.merge(key, 1, Integer::sum);
                best = Math.max(best, count + 1);
            }
        }
        return best;
    }

    private long gcd(long a, long b) {
        a = Math.abs(a);
        b = Math.abs(b);
        while (b != 0) {
            long t = b;
            b = a % b;
            a = t;
        }
        return a;
    }
}
