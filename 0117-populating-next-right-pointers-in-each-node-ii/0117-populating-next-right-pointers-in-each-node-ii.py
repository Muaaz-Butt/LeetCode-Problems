"""
# Definition for a Node.
class Node:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""

class Solution:
    def connect(self, root: 'Node') -> 'Node':
        head = None
        prev = None
        current = root

        while current:
            while current:
                if current.left:
                    if prev:
                        prev.next = current.left
                    else:
                        head = current.left
                    prev = current.left
                if current.right:
                    if prev:
                        prev.next = current.right
                    else:
                        head = current.right
                    prev = current.right
                current = current.next
            current = head
            head = None
            prev = None
        
        return root

                    

