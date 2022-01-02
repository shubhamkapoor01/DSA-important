class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !k) {
            return head;
        }
        
        int len = 0;
        ListNode* t = head;
        
        while (t && t -> next) {
            len ++;
            t = t -> next;
        }
        
        len ++;
        k = k % len;
        t -> next = head;
        t = head;
        int cnt = 0;
        
        while (cnt < len - k - 1) {
            t = t -> next;
            cnt ++;
        }
        
        head = t -> next;
        t -> next = nullptr;
        
        return head;
    }
};
