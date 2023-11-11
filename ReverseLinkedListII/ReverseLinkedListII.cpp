/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* current = head;
        for (int i = 0; i < left - 1; i++) {
            prev = prev->next;
            current = current->next;
        }
        ListNode* subHead = current;
        ListNode* preNode = nullptr;
        for (int i = 0; i < right - left + 1; i++) {
            ListNode* currNext = current->next;
            current->next = preNode;
            preNode = current;
            current = currNext;
        }
        prev->next = preNode;
        subHead->next = current;
        return dummy->next;
    }
};


/* First create dummy node wich will point to the head 
   Then start first loop which will point the pointer to the node previous from the startng node and move the current
   pointer to the starting point then declare the new pointer which will point to the null and then start 
   loop which will execute to the right - left + 1 times and adjust pointers and at the end adjust the first and 
   last starting pointers*/