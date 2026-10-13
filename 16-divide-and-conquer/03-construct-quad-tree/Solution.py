# Definition for a QuadTree node.
class Node:
    def __init__(self, val, isLeaf, topLeft=None, topRight=None, bottomLeft=None, bottomRight=None):
        self.val = val
        self.isLeaf = isLeaf
        self.topLeft = topLeft
        self.topRight = topRight
        self.bottomLeft = bottomLeft
        self.bottomRight = bottomRight

class Solution:
    def construct(self, grid: list[list[int]]) -> 'Node':
        def build(r: int, c: int, size: int) -> 'Node':
            first = grid[r][c]
            uniform = all(
                grid[r + i][c + j] == first
                for i in range(size) for j in range(size)
            )
            if uniform:
                return Node(bool(first), True)
            half = size // 2
            tl = build(r, c, half)
            tr = build(r, c + half, half)
            bl = build(r + half, c, half)
            br = build(r + half, c + half, half)
            return Node(True, False, tl, tr, bl, br)

        return build(0, 0, len(grid))
