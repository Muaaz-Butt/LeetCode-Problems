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
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        } 
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* current = head->next->next;
        while(even != nullptr && even->next != nullptr){
            even->next = current->next;
            current->next = odd->next;
            odd->next = current;
            even = even->next;
            if(even)
                current = even->next;
            odd = odd->next;
        }
        return head;
    }
};