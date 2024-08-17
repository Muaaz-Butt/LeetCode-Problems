# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        if not list1 :
            return list2
        if not list2:
            return list1
        temp = list1
        if list1.val > list2.val:
            temp = list2
            list2 = list2.next
        else:
            list1 = list1.next
        current = temp
        while list1 and list2:
            if list1.val < list2.val:
                current.next = list1
                list1 = list1.next
            else:
                current.next = list2
                list2 = list2.next
            current = current.next
        if not list1:
            current.next = list2
        else:
            current.next = list1
        return temp