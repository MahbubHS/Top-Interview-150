class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 2) return n;
        int best = 1;
        for (int i = 0; i < n; i++) {
            unordered_map<long long, int> slopes;
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                long long dx = points[j][0] - points[i][0];
                long long dy = points[j][1] - points[i][1];
                long long g = __gcd(dx, dy);
                if (g) { dx /= g; dy /= g; }
                if (dx < 0 || (dx == 0 && dy < 0)) { dx = -dx; dy = -dy; }
                long long key = dx * 200001LL + dy;
                slopes[key]++;
                best = max(best, slopes[key] + 1);
            }
        }
        return best;
    }
};
