int floorInBST(TreeNode<int> * root, int X) {
    if (!root) {
        return 0;
    }
    
    if (root -> val == X) {
        return root -> val;
    }
    
    if (root -> val < X) {
        return max(floorInBST(root -> right, X), root -> val);
    }
    
    return floorInBST(root -> left, X);
}
