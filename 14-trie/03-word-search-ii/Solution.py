class Solution:
    def findWords(self, board: list[list[str]], words: list[str]) -> list[str]:
        root: dict = {}
        for w in words:
            node = root
            for ch in w:
                node = node.setdefault(ch, {})
            node['$'] = w

        rows, cols = len(board), len(board[0])
        res = []

        def dfs(r, c, parent):
            ch = board[r][c]
            node = parent[ch]
            if '$' in node:
                res.append(node.pop('$'))
            board[r][c] = '#'
            for dr, dc in ((1, 0), (-1, 0), (0, 1), (0, -1)):
                nr, nc = r + dr, c + dc
                if 0 <= nr < rows and 0 <= nc < cols and board[nr][nc] in node:
                    dfs(nr, nc, node)
            board[r][c] = ch
            if not node:
                parent.pop(ch)

        for r in range(rows):
            for c in range(cols):
                if board[r][c] in root:
                    dfs(r, c, root)
        return res
