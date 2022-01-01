class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = new ListNode(0);
        ListNode* t = ans;
        
        int s = 0;
        int c = 0;
        
        while (l1 && l2) {
            s = (c + l1 -> val + l2 -> val) % 10;
            c = (c + l1 -> val + l2 -> val) / 10;
            
            t -> next = new ListNode(s);
            t = t -> next;
            
            l1 = l1 -> next;
            l2 = l2 -> next;
        }
        
        while (l1) {
            s = (c + l1 -> val) % 10;
            c = (c + l1 -> val) / 10;
            
            t -> next = new ListNode(s);
            t = t -> next;
            
            l1 = l1 -> next;
        }
        
        while (l2) {
            s = (c + l2 -> val) % 10;
            c = (c + l2 -> val) / 10;
            
            t -> next = new ListNode(s);
            t = t -> next;
            
            l2 = l2 -> next;
        }
        
        if (c != 0) {
            t -> next = new ListNode(c);
        }
        
        return ans -> next;
    }
};
