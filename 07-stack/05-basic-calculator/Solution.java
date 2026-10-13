import java.util.ArrayDeque;
import java.util.Deque;

class Solution {
    public int calculate(String s) {
        Deque<Long> stack = new ArrayDeque<>();
        long result = 0, number = 0;
        int sign = 1;
        for (char ch : s.toCharArray()) {
            if (Character.isDigit(ch)) {
                number = number * 10 + (ch - '0');
            } else if (ch == '+') {
                result += sign * number;
                number = 0;
                sign = 1;
            } else if (ch == '-') {
                result += sign * number;
                number = 0;
                sign = -1;
            } else if (ch == '(') {
                stack.push(result);
                stack.push((long) sign);
                result = 0;
                sign = 1;
            } else if (ch == ')') {
                result += sign * number;
                number = 0;
                long prevSign = stack.pop();
                long prevResult = stack.pop();
                result = prevResult + prevSign * result;
            }
        }
        result += sign * number;
        return (int) result;
    }
}
