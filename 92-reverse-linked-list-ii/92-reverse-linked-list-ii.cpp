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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode(0);
        
        dummy -> next = head;
        ListNode* curr = dummy;
        ListNode* prev;
        
        while (left -- && right -- && curr) {
            prev = curr;
            curr = curr -> next;
        }
        
        ListNode* next = nullptr;
        ListNode* store = prev;
        curr = curr -> next;
        prev = prev -> next;
        ListNode* front = prev;
        
        while (curr && right --) {
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        
        store -> next = prev;
        front -> next = curr;
        return dummy -> next;
    }
};