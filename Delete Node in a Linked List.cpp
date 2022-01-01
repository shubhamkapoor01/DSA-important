class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* t = node;
        t -> val = t -> next -> val;
        ListNode* temp = node -> next;
        t -> next = t -> next -> next;
        delete temp;
    }
};
