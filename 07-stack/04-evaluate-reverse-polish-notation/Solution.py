class Solution:
    def evalRPN(self, tokens: list[str]) -> int:
        stack: list[int] = []
        ops = {'+', '-', '*', '/'}
        for token in tokens:
            if token in ops:
                b = stack.pop()
                a = stack.pop()
                if token == '+':
                    stack.append(a + b)
                elif token == '-':
                    stack.append(a - b)
                elif token == '*':
                    stack.append(a * b)
                else:
                    # truncate toward zero, unlike Python's default floor division
                    stack.append(int(a / b))
            else:
                stack.append(int(token))
        return stack[-1]
