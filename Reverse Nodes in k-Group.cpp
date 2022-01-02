class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || !head -> next) {
            return head;
        }
        
        int len = 0;
        ListNode* temp = head;
        
        while (temp) {
            temp = temp -> next;
            len ++;
        }
        
        if (len < k) {
            return head;
        }
        
        int t = k;
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = curr -> next;
        
        while (t -- && curr) {
            curr -> next = prev;
            prev = curr;
            curr = next;
            if (next) {
                next = next -> next;
            }
        }
        
        head -> next = reverseKGroup(curr, k);
        return prev;
    }
};
