class Solution {
public:
    ListNode* getMiddle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast and fast -> next and fast -> next -> next) {
            fast = fast -> next -> next;
            slow = slow -> next;
        }
        
        return slow;
    }
    
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* next = nullptr;
        ListNode* curr = head;
        
        while(curr) {
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        
        return prev;
    }
    
    bool isPalindrome(ListNode* head) {
        
        ListNode* mid = getMiddle(head);
        mid -> next = reverseList(mid -> next);
        mid = mid -> next;
        
        while(mid) {
            if(head -> val != mid -> val)
                return false;
            mid = mid -> next;
            head = head -> next;
        }
        return true;
    }
};
