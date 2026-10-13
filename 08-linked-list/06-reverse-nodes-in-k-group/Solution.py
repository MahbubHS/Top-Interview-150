# Definition for singly-linked list node.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def reverseKGroup(self, head: 'ListNode', k: int) -> 'ListNode':
        dummy = ListNode(0, head)
        prev_group_end = dummy

        while True:
            kth = prev_group_end
            for _ in range(k):
                kth = kth.next
                if not kth:
                    return dummy.next
            group_start = prev_group_end.next
            next_group_start = kth.next

            prev, current = next_group_start, group_start
            while current != next_group_start:
                next_node = current.next
                current.next = prev
                prev = current
                current = next_node

            prev_group_end.next = kth
            prev_group_end = group_start
