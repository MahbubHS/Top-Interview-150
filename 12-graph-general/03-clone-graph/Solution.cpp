class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() : val(0), neighbors(vector<Node*>()) {}
    Node(int _val) : val(_val), neighbors(vector<Node*>()) {}
    Node(int _val, vector<Node*> _neighbors) : val(_val), neighbors(_neighbors) {}
};

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        unordered_map<Node*, Node*> clones;
        clones[node] = new Node(node->val);
        vector<Node*> stack = {node};
        while (!stack.empty()) {
            Node* cur = stack.back();
            stack.pop_back();
            for (Node* nb : cur->neighbors) {
                if (!clones.count(nb)) {
                    clones[nb] = new Node(nb->val);
                    stack.push_back(nb);
                }
                clones[cur]->neighbors.push_back(clones[nb]);
            }
        }
        return clones[node];
    }
};
