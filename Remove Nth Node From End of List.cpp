class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (n == 0) {
            return head;
        }
        
        ListNode* t = head;
        int len = 0;
        
        while (t) {
            len ++;
            t = t -> next;
        }
        
        if (n == len) {
            return head -> next;
        }
        
        t = head;
        
        while (len > n + 1) {
            t = t -> next;
            len --;
        }
        
        ListNode* temp = t -> next;
        t -> next = t -> next -> next;
        delete temp;
        return head;
    }
};
