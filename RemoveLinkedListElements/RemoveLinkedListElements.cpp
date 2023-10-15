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
    ListNode* removeElements(ListNode* head, int value) {
        ListNode* dummy = new ListNode(0);
        ListNode* current = head;
        dummy->next = head;
        ListNode* prev = dummy;
        while (current != nullptr) {
            if (current->val == value) {
                ListNode* p = current;
                prev->next = current->next;
                current = current->next;
                delete p;
            }
            else {
                current = current->next;
                prev = prev->next;
            }
        }
        return dummy->next;
    }
};