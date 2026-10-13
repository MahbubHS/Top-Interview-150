struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode beforeHead(0), afterHead(0);
        ListNode* before = &beforeHead;
        ListNode* after = &afterHead;
        ListNode* current = head;
        while (current) {
            if (current->val < x) {
                before->next = current;
                before = before->next;
            } else {
                after->next = current;
                after = after->next;
            }
            current = current->next;
        }
        after->next = nullptr;
        before->next = afterHead.next;
        return beforeHead.next;
    }
};
