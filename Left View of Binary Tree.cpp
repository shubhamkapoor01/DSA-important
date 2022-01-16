void solve(Node* root, vector<int> &left, int height) {
    if (!root) {
        return;
    }    
    
    if (height == left.size()) {
        left.push_back(root -> data);
    }
    
    solve(root -> left, left, height + 1);
    solve(root -> right, left, height + 1);
}

vector<int> leftView(Node *root) {
    vector<int> left;
    solve(root, left, 0);
    return left;
}
