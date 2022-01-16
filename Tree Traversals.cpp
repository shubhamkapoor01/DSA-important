void solve(BinaryTreeNode<int> *root, vector<int> &inorder, 
           vector<int> &preorder, vector<int> &postorder) {
    
    if (!root) {
        return;
    }
    
    preorder.push_back(root -> data);
    solve(root -> left, inorder, preorder, postorder);
    inorder.push_back(root -> data);
    solve(root -> right, inorder, preorder, postorder);
    postorder.push_back(root -> data);
    return;
}

vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    vector<int> inorder;
    vector<int> preorder;
    vector<int> postorder;
    
   	solve(root, inorder, preorder, postorder);
    return {inorder, preorder, postorder};
}
