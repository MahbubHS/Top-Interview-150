# Definition for singly-linked list node.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def deleteDuplicates(self, head: 'ListNode') -> 'ListNode':
        dummy = ListNode(0, head)
        prev = dummy
        current = head
        while current:
            if current.next and current.val == current.next.val:
                val = current.val
                while current and current.val == val:
                    current = current.next
                prev.next = current
            else:
                prev = current
                current = current.next
        return dummy.next
