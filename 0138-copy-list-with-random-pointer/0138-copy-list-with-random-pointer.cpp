/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) {
            return nullptr;
        }
        Node* curr = head;

        while(curr != nullptr) {
            Node* new_node = new Node(curr->val);
            new_node->next = curr->next;
            curr->next = new_node;
            curr = new_node->next;
        }
        curr = head;

        while (curr) {
            if (curr->random)
                curr->next->random = curr->random->next;
            curr = curr->next->next;
        }
        
        Node* old_head = head;
        Node* new_head = head->next;
        Node* curr_old = old_head;
        Node* curr_new = new_head;

        while(curr_old) {
            curr_old->next = curr_new->next;
            curr_old = curr_old->next;
            if (curr_old != nullptr){
                curr_new->next = curr_old->next;
                curr_new = curr_new->next;
            }
        }

        return new_head;

    }
};