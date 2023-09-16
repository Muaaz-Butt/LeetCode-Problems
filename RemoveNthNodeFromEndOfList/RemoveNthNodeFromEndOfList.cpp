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
    void removeNodeAtTail(ListNode* head) {
        if (head->next == nullptr) {
            cout << head;
            delete head;
            head = nullptr;
            return;
        }
        ListNode* temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (n == 1) {
            if (head->next == nullptr) {
                delete head;
                head = nullptr;
                return head;
            }
        }
        int i = 0;
        int nodeToBeDeleted = 0;
        ListNode* temp = head;
        while (temp != nullptr) {
            temp = temp->next;
            i++;
        }
        nodeToBeDeleted = i - n + 1;
        if (nodeToBeDeleted == i) {
            ListNode* temp = head;
            while (temp->next->next != nullptr) {
                temp = temp->next;
            }
            delete temp->next;
            temp->next = nullptr;
            return head;
        }
        if (nodeToBeDeleted == 1) {
            ListNode* p = head;
            head = head->next;
            delete p;
            return head;
        }
        temp = head;
        i = 1;
        ListNode* prev = nullptr;
        while (temp != nullptr) {
            if (i == nodeToBeDeleted) {
                prev->next = temp->next;
                delete temp;
                break;
            }
            prev = temp;
            temp = temp->next;
            i++;
        }
        return head;
    }
};