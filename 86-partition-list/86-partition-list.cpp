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
    ListNode* partition(ListNode* head, int x) {
        ListNode* dummyLess = new ListNode(0);
        ListNode* dummyMore = new ListNode(0);
        ListNode* more = dummyMore;
        ListNode* less = dummyLess;
        ListNode* it = head;
        
        while (it) {
            if (it -> val < x) {
                less -> next = it;
                it = it -> next;
                less = less -> next;
                less -> next = nullptr;
            } else {
                more -> next = it;
                it = it -> next;
                more = more -> next;
                more -> next = nullptr;
            }
        }
        
        less -> next = dummyMore -> next;
        return dummyLess -> next;
    }
};