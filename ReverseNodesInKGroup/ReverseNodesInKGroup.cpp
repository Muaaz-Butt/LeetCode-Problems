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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr || k == 1) {
            return head;
        }
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* temp = head;
        while (temp) {
            ListNode* tail = prev;
            for (int i = 0; i < k; i++) {
                tail = tail->next;
                if (tail == nullptr) {
                    return dummy->next;
                }
            }
            ListNode* newHead = tail->next;
            ListNode* current = temp;
            ListNode* prevNode = newHead;
            while (current != newHead) {
                ListNode* next = current->next;
                current->next = prevNode;
                prevNode = current;
                current = next;
            }
            prev->next = tail;
            temp->next = newHead;
            prev = temp;
            temp = newHead;
        }
        return dummy->next;
    }
};