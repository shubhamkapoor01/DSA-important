class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        
        while (fast && fast -> next) {
            fast = fast -> next -> next;
            slow = slow -> next;
        }
        
        ListNode* t = head;
        while (slow && t) {
            if (slow -> val == t -> val) {
                return false;
            }
            
            slow = slow -> next;
            t = t -> next;
        }
        
        return true;
    }
};
