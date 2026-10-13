class Solution:
    def numIslands(self, grid: list[list[str]]) -> int:
        rows, cols = len(grid), len(grid[0])
        count = 0
        for r in range(rows):
            for c in range(cols):
                if grid[r][c] == '1':
                    count += 1
                    grid[r][c] = '0'
                    stack = [(r, c)]
                    while stack:
                        x, y = stack.pop()
                        for dx, dy in ((1, 0), (-1, 0), (0, 1), (0, -1)):
                            nx, ny = x + dx, y + dy
                            if 0 <= nx < rows and 0 <= ny < cols and grid[nx][ny] == '1':
                                grid[nx][ny] = '0'
                                stack.append((nx, ny))
        return count
