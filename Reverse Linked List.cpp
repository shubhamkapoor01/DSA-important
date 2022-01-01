class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head) {
            return head;
        }
        
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = curr -> next;
        
        while (curr) {
            curr -> next = prev;
            prev = curr;
            curr = next;
            if (next) {
                next = next -> next;
            }
        }
        
        return prev;
    }
};
