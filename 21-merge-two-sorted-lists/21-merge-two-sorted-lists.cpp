/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1) return list2;
        if (!list2) return list1;
        
        if (list1 -> val > list2 -> val) {
            swap(list1, list2);
        }
        
        ListNode* a = list1;
        ListNode* b = list2;
        ListNode* t = new ListNode;
        
        while (a && b) {
            if (a -> val <= b -> val) {
                t -> next = a;
                t = a;
                a = a -> next;
                
            } else {
                t -> next = b;
                t = b;
                b = b -> next;
            }
        }
        
        if (a) t -> next = a;
        if (b) t -> next = b;
        
        return list1;
    }
};