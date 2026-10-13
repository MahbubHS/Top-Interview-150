class Solution {
public:
    int trailingZeroes(int n) {
        int count = 0;
        long power = 5;
        while (power <= n) {
            count += n / power;
            power *= 5;
        }
        return count;
    }
};
