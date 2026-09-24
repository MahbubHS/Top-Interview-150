class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = (int)height.size() - 1, best = 0;
        while (l < r) {
            int area = min(height[l], height[r]) * (r - l);
            best = max(best, area);
            if (height[l] < height[r]) l++;
            else r--;
        }
        return best;
    }
};
