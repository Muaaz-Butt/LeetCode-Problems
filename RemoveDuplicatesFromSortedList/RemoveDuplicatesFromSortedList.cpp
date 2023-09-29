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
	ListNode* deleteDuplicates(ListNode* head) {
		ListNode* temp = head;
		ListNode* temp1 = nullptr;
		while (temp != nullptr) {
			temp1 = temp->next;
			while (temp1 != nullptr && temp1->val == temp->val) {
				ListNode* p = temp1->next;
				temp1 = temp1->next;
				delete temp->next;
				temp->next = p;
			}
			temp = temp->next;
		}
		return head;
	}
};