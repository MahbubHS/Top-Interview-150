class Node {
    public boolean val;
    public boolean isLeaf;
    public Node topLeft;
    public Node topRight;
    public Node bottomLeft;
    public Node bottomRight;

    public Node() {}
    public Node(boolean val, boolean isLeaf) {
        this.val = val;
        this.isLeaf = isLeaf;
    }
    public Node(boolean val, boolean isLeaf, Node topLeft, Node topRight, Node bottomLeft, Node bottomRight) {
        this.val = val;
        this.isLeaf = isLeaf;
        this.topLeft = topLeft;
        this.topRight = topRight;
        this.bottomLeft = bottomLeft;
        this.bottomRight = bottomRight;
    }
}

class Solution {
    public Node construct(int[][] grid) {
        return build(grid, 0, 0, grid.length);
    }

    private Node build(int[][] grid, int r, int c, int size) {
        int first = grid[r][c];
        boolean uniform = true;
        outer:
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (grid[r + i][c + j] != first) { uniform = false; break outer; }
            }
        }
        if (uniform) return new Node(first != 0, true);
        int half = size / 2;
        Node tl = build(grid, r, c, half);
        Node tr = build(grid, r, c + half, half);
        Node bl = build(grid, r + half, c, half);
        Node br = build(grid, r + half, c + half, half);
        return new Node(true, false, tl, tr, bl, br);
    }
}
