/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* it = node;
        it -> val = it -> next -> val;
        ListNode* temp = it -> next;
        it -> next = it -> next -> next;
        delete temp;
    }
};