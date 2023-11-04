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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        if (k == 0) {
            return head;
        }
        ListNode* temp = head;
        int length = 0;
        while (temp != nullptr) {
            temp = temp->next;
            length++;
        }
        k %= length;
        temp = head->next;
        ListNode* prev = head;
        int i = 0;
        while (i < k) {
            if (temp->next == nullptr) {
                temp->next = head;
                head = temp;
                prev->next = nullptr;
                i++;
                if (i < k)
                {
                    temp = head->next;
                    prev = head;
                }
            }
            else {
                temp = temp->next;
                prev = prev->next;
            }
        }
        return head;
    }
};