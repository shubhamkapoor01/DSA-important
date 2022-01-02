class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
        
        while (fast && fast -> next) {
            fast = fast -> next -> next;
            slow = slow -> next;
            
            if (fast == slow) {
                break;
            }
        }
        
        if (fast != slow || !fast || !fast -> next) {
            return nullptr;
        }
        
        fast = head;
        while (fast != slow) {
            fast = fast -> next;
            slow = slow -> next;
        }
        
        return fast;
    }
};
