class Solution:
    def generateParenthesis(self, n: int) -> list[str]:
        res = []

        def bt(open_count, close_count, path):
            if len(path) == 2 * n:
                res.append(''.join(path))
                return
            if open_count < n:
                path.append('(')
                bt(open_count + 1, close_count, path)
                path.pop()
            if close_count < open_count:
                path.append(')')
                bt(open_count, close_count + 1, path)
                path.pop()

        bt(0, 0, [])
        return res
