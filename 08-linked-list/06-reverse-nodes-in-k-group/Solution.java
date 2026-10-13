class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}

class Solution {
    public ListNode reverseKGroup(ListNode head, int k) {
        ListNode dummy = new ListNode(0, head);
        ListNode prevGroupEnd = dummy;

        while (true) {
            ListNode kth = prevGroupEnd;
            for (int i = 0; i < k; i++) {
                kth = kth.next;
                if (kth == null) return dummy.next;
            }
            ListNode groupStart = prevGroupEnd.next;
            ListNode nextGroupStart = kth.next;

            ListNode prev = nextGroupStart;
            ListNode current = groupStart;
            while (current != nextGroupStart) {
                ListNode nextNode = current.next;
                current.next = prev;
                prev = current;
                current = nextNode;
            }

            prevGroupEnd.next = kth;
            prevGroupEnd = groupStart;
        }
    }
}
