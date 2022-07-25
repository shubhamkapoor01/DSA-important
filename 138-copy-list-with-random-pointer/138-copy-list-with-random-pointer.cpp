/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        Node* it = head;
        
        while (it) {
            Node* copy = new Node(it -> val);
            Node* temp = it -> next;
            it -> next = copy;
            copy -> next = temp;
            it = it -> next -> next;
        }
        
        it = head;
        while (it) {
            if (it -> random) it -> next -> random = it -> random -> next;
            else it -> next -> random = nullptr;
            it = it -> next -> next;
        }
        
        Node* copy = head -> next;
        Node* cit = copy;
        it = head;
        
        while (it && cit && it -> next) {
            Node* temp = cit -> next;
            if (cit -> next) cit -> next = cit -> next -> next;
            else cit -> next = nullptr;
            it -> next = temp;
            cit = cit -> next;
            it = it -> next;
        }
        
        return copy;
    }
};