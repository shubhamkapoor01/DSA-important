class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) {
            return nullptr;
        }
        
        Node* temp = head;
        while (temp) {
            Node* t = new Node(temp -> val);
            t -> next = temp -> next;
            temp -> next = t;
            temp = temp -> next -> next;
        }
        
        Node* rand = head;
        while (rand) {
            if (rand -> random) {
                rand -> next -> random = rand -> random -> next;
            } else {
                rand -> next -> random = nullptr;
            }
            rand = rand -> next -> next;
        }
        
        Node* orig = head;
        Node* newHead = head -> next;
        Node* newLL = head -> next;
        
        while (orig && newLL) {
            orig -> next = orig -> next -> next;
            if (newLL -> next) {
                newLL -> next = newLL -> next -> next;
            }
            orig = orig -> next;
            newLL = newLL -> next;
        }
        
        return newHead;
    }
};
