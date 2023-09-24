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
    ListNode* middleNode(ListNode* head) {
        if (head->next == nullptr) {
            return head;
        }
        if (head->next->next == nullptr) {
            return head->next;
        }
        ListNode* temp = head;
        ListNode* midNode = head;
        int count = 0;
        while (temp != nullptr) {
            temp = temp->next;
            count++;
        }
        if (count % 2 == 1) {
            int mid = count / 2;
            int i = 0;
            while (i < mid) {
                i++;
                midNode = midNode->next;
            }
            return midNode;
        }
        int mid = count / 2;
        for (int i = 0; i < mid; i++) {
            midNode = midNode->next;
        }
        return midNode;
    }
};