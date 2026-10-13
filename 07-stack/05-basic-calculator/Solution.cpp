class Solution {
public:
    int calculate(string s) {
        stack<long long> st;
        long long result = 0, number = 0;
        int sign = 1;
        for (char ch : s) {
            if (isdigit((unsigned char)ch)) {
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
                st.push(result);
                st.push(sign);
                result = 0;
                sign = 1;
            } else if (ch == ')') {
                result += sign * number;
                number = 0;
                int prevSign = st.top(); st.pop();
                long long prevResult = st.top(); st.pop();
                result = prevResult + prevSign * result;
            }
        }
        result += sign * number;
        return (int)result;
    }
};
