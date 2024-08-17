# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        carry = 0
        dummy = ListNode(0)
        current = dummy

        while l1 or l2 or carry:
            sum_val = (l1.val if l1 else 0) + (l2.val if l2 else 0) + carry
            carry = sum_val // 10
            current.next = ListNode(sum_val % 10)

            if l1:
                l1 = l1.next
            if l2:
                l2 = l2.next
            current = current.next
        
        return dummy.next