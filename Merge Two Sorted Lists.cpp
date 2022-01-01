class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1) {
            return list2;
        } 
        
        if (!list2) {
            return list1;
        }
        
        ListNode* t1;
        ListNode* t2;
        ListNode* head;
        ListNode* t = NULL;
        
        if (list1 -> val <= list2 -> val) {
            head = list1;
            t1 = list1;
            t2 = list2;
        } else {
            head = list2;
            t1 = list2;
            t2 = list1;
        }
        
        while (t1 && t2) {
            if (!t) {
                if (t1 -> val <= t2 -> val) {
                    t = t1;
                    t1 = t1 -> next;
                } else {
                    t = t2;
                    t2 = t2 -> next;
                }
                continue;
            }
            
            if (t1 -> val <= t2 -> val) {
                t = t1;
                t1 = t1 -> next;
                
            } else {
                ListNode* temp = t2;
                t2 = t2 -> next;
                temp -> next = t1;
                t -> next = temp;
                t = temp;
            }
        }
        
        if (!t1) {
            t -> next = t2;
        }
        
        return head;
    }
};
