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
    ListNode* partition(ListNode* head, int x) {
        ListNode* less_head = new ListNode(0);
        ListNode* greater_head = new ListNode(0);

        ListNode* less = less_head;
        ListNode* greater = greater_head;

        while(head) {
            if (head->val < x) {
                less->next = head;
                less = less->next;
            } 
            else{
                greater->next = head;
                greater = greater->next; 
            }
            head = head->next;
        }
        greater->next = nullptr;
        less->next = greater_head->next;

        return less_head->next;
    }
};