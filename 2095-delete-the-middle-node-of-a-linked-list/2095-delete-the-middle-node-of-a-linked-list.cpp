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
    ListNode* deleteMiddle(ListNode* head) {
        if (!head -> next) {
            return nullptr;
        }
        
        if (!head -> next -> next) {
            ListNode* temp = head -> next;
            head -> next = nullptr;
            delete temp;
            return head;
        }
        
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* del = nullptr;
        
        while (fast && fast -> next) {
            fast = fast -> next -> next;
            del = slow;
            slow = slow -> next;
        }
        
        del -> next = slow -> next;
        delete slow;
        return head;
    }
};