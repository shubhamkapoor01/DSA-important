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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode;
        dummy -> next = head;
        
        ListNode* it1 = dummy;
        ListNode* it2 = dummy;
        
        for (int i = 0; i <= n; i ++) {
            it1 = it1 -> next;
        }
        
        while (it1) {
            it2 = it2 -> next;
            it1 = it1 -> next;
        }
        
        it2 -> next = it2 -> next -> next;
        return dummy -> next;
    }
};