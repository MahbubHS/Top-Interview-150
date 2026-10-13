import java.util.ArrayList;
import java.util.List;

class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}

class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        if (lists.length == 0) return null;
        List<ListNode> cur = new ArrayList<>();
        for (ListNode l : lists) cur.add(l);
        while (cur.size() > 1) {
            List<ListNode> merged = new ArrayList<>();
            for (int i = 0; i < cur.size(); i += 2) {
                ListNode l1 = cur.get(i);
                ListNode l2 = (i + 1 < cur.size()) ? cur.get(i + 1) : null;
                merged.add(merge(l1, l2));
            }
            cur = merged;
        }
        return cur.get(0);
    }

    private ListNode merge(ListNode l1, ListNode l2) {
        ListNode dummy = new ListNode(0);
        ListNode cur = dummy;
        while (l1 != null && l2 != null) {
            if (l1.val <= l2.val) { cur.next = l1; l1 = l1.next; }
            else { cur.next = l2; l2 = l2.next; }
            cur = cur.next;
        }
        cur.next = (l1 != null) ? l1 : l2;
        return dummy.next;
    }
}
