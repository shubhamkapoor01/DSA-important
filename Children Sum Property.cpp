void solve(BinaryTreeNode<int>* root, int &mx) {
	if (!root) {
        return;
    }
    
    mx = max(mx, root -> data);
    
    if (!root -> left && !root -> right) {
        root -> data = mx;
        return;
    }
    
    solve(root -> left, mx);
    solve(root -> right, mx);
    root -> data = 0;
    
    if (root -> left) {
        root -> data += root -> left -> data;
    }
    if (root -> right) {
        root -> data += root -> right -> data;
    }
}

void changeTree(BinaryTreeNode<int>* root) {
    int mx = 0;
    solve(root, mx);
	return;
}
