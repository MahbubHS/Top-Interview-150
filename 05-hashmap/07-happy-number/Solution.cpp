class Solution {
    int nextVal(int x) {
        int total = 0;
        while (x > 0) {
            int digit = x % 10;
            total += digit * digit;
            x /= 10;
        }
        return total;
    }
public:
    bool isHappy(int n) {
        unordered_set<int> seen;
        while (n != 1 && !seen.count(n)) {
            seen.insert(n);
            n = nextVal(n);
        }
        return n == 1;
    }
};
