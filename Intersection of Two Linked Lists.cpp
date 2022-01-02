class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *t1 = headA;
        ListNode *t2 = headB;
        int len1 = 0;
        int len2 = 0;
        
        while (t1) {
            len1 ++;
            t1 = t1 -> next;
        }
        
        while (t2) {
            len2 ++;
            t2 = t2 -> next;
        }
        
        if (len1 < len2) {
            t1 = headB;
            t2 = headA;
            swap(len1, len2);
            
        } else {
            t1 = headA;
            t2 = headB;
        }
        
        int k = 0;
        
        while (k < len1 - len2) {
            t1 = t1 -> next;
            k ++;
        }
    
        while (t1 != t2 && t1 && t2) {
            t1 = t1 -> next;
            t2 = t2 -> next;
        }
            
        return t1;
    }
};
