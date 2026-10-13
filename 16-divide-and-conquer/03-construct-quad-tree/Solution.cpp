class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() : val(false), isLeaf(false), topLeft(NULL), topRight(NULL), bottomLeft(NULL), bottomRight(NULL) {}
    Node(bool _val, bool _isLeaf) : val(_val), isLeaf(_isLeaf), topLeft(NULL), topRight(NULL), bottomLeft(NULL), bottomRight(NULL) {}
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight)
        : val(_val), isLeaf(_isLeaf), topLeft(_topLeft), topRight(_topRight), bottomLeft(_bottomLeft), bottomRight(_bottomRight) {}
};

class Solution {
    Node* build(vector<vector<int>>& grid, int r, int c, int size) {
        int first = grid[r][c];
        bool uniform = true;
        for (int i = 0; i < size && uniform; i++) {
            for (int j = 0; j < size; j++) {
                if (grid[r + i][c + j] != first) { uniform = false; break; }
            }
        }
        if (uniform) return new Node((bool)first, true);
        int half = size / 2;
        Node* tl = build(grid, r, c, half);
        Node* tr = build(grid, r, c + half, half);
        Node* bl = build(grid, r + half, c, half);
        Node* br = build(grid, r + half, c + half, half);
        return new Node(true, false, tl, tr, bl, br);
    }
public:
    Node* construct(vector<vector<int>>& grid) {
        return build(grid, 0, 0, grid.size());
    }
};
