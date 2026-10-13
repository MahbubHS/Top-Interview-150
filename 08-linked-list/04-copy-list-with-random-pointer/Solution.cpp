class Node {
public:
    int val;
    Node* next;
    Node* random;
    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        unordered_map<Node*, Node*> oldToNew;
        Node* current = head;
        while (current) {
            oldToNew[current] = new Node(current->val);
            current = current->next;
        }
        current = head;
        while (current) {
            oldToNew[current]->next = current->next ? oldToNew[current->next] : nullptr;
            oldToNew[current]->random = current->random ? oldToNew[current->random] : nullptr;
            current = current->next;
        }
        return oldToNew[head];
    }
};
