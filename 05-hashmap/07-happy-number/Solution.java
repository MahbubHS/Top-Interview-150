import java.util.HashSet;
import java.util.Set;

class Solution {
    private int nextVal(int x) {
        int total = 0;
        while (x > 0) {
            int digit = x % 10;
            total += digit * digit;
            x /= 10;
        }
        return total;
    }

    public boolean isHappy(int n) {
        Set<Integer> seen = new HashSet<>();
        while (n != 1 && !seen.contains(n)) {
            seen.add(n);
            n = nextVal(n);
        }
        return n == 1;
    }
}
