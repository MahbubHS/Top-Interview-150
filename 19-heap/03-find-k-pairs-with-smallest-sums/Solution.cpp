class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> res;
        if (nums1.empty() || nums2.empty()) return res;
        auto cmp = [](const tuple<int,int,int>& a, const tuple<int,int,int>& b) {
            return get<0>(a) > get<0>(b);
        };
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, decltype(cmp)> heap(cmp);
        for (int i = 0; i < (int)min((size_t)k, nums1.size()); i++) {
            heap.push({nums1[i] + nums2[0], i, 0});
        }
        while (!heap.empty() && (int)res.size() < k) {
            auto [sum, i, j] = heap.top();
            heap.pop();
            res.push_back({nums1[i], nums2[j]});
            if (j + 1 < (int)nums2.size()) {
                heap.push({nums1[i] + nums2[j + 1], i, j + 1});
            }
        }
        return res;
    }
};
