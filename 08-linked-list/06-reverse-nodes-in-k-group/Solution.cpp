struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0, head);
        ListNode* prevGroupEnd = &dummy;

        while (true) {
            ListNode* kth = prevGroupEnd;
            for (int i = 0; i < k; i++) {
                kth = kth->next;
                if (!kth) return dummy.next;
            }
            ListNode* groupStart = prevGroupEnd->next;
            ListNode* nextGroupStart = kth->next;

            ListNode* prev = nextGroupStart;
            ListNode* current = groupStart;
            while (current != nextGroupStart) {
                ListNode* nextNode = current->next;
                current->next = prev;
                prev = current;
                current = nextNode;
            }

            prevGroupEnd->next = kth;
            prevGroupEnd = groupStart;
        }
    }
};
