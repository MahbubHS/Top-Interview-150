class Solution:
    def calculate(self, s: str) -> int:
        stack: list[int] = []
        result = 0
        number = 0
        sign = 1
        for ch in s:
            if ch.isdigit():
                number = number * 10 + int(ch)
            elif ch == '+':
                result += sign * number
                number = 0
                sign = 1
            elif ch == '-':
                result += sign * number
                number = 0
                sign = -1
            elif ch == '(':
                # push the running result and the sign that applies to this group
                stack.append(result)
                stack.append(sign)
                result = 0
                sign = 1
            elif ch == ')':
                result += sign * number
                number = 0
                result *= stack.pop()   # sign that applied before '('
                result += stack.pop()   # result accumulated before '('
        result += sign * number
        return result
