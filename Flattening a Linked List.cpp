Node *flatten(Node *root) {
    Node* top = root;
    Node* res = new Node(-1);
    Node* head = res;
    
    while(root -> data != INT_MAX){
        Node* minNode = top;
        
        while (top) {
            if (minNode -> data > top -> data)
                minNode = top;
            top = top -> next;
        }   
        
        top = root;
        res -> bottom = new Node(minNode -> data);
        res = res -> bottom;
        
        if (minNode -> bottom != NULL){
            Node* temp = minNode -> bottom;
            minNode -> data = temp -> data;
            minNode -> bottom = temp -> bottom;
            delete temp;
            
        } else if (minNode -> next != NULL) {
            Node* temp = minNode -> next;
            minNode -> data = temp -> data;
            minNode -> bottom = temp -> bottom;
            minNode -> next = temp -> next;
            delete temp;
            
        } else {
          minNode -> data = INT_MAX;
        }
    }
    
    return head->bottom;
}
