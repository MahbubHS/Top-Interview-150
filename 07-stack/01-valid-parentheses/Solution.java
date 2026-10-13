import java.util.HashMap;
import java.util.Map;
import java.util.Deque;
import java.util.ArrayDeque;

class Solution {
    public boolean isValid(String s) {
        Map<Character, Character> pairs = new HashMap<>();
        pairs.put(')', '('); pairs.put(']', '['); pairs.put('}', '{');
        Deque<Character> stack = new ArrayDeque<>();
        for (char ch : s.toCharArray()) {
            if (pairs.containsKey(ch)) {
                if (stack.isEmpty() || stack.pop() != pairs.get(ch)) return false;
            } else {
                stack.push(ch);
            }
        }
        return stack.isEmpty();
    }
}
