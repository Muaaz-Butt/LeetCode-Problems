# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def rotateRight(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        if not head or head.next == None:
            return head
        curr = head
        length = 0
        while curr:
            curr = curr.next
            length += 1
        k = k % length
        if k == 0:
            return head
        i = 0
        curr = head.next
        prev = head
        
        while i < k:
            if curr.next == None:
                curr.next = head
                prev.next = None
                head = curr
                i += 1
                if i < k:
                    curr = head.next
                    prev = head
            else:
                curr = curr.next
                prev = prev.next
        return head