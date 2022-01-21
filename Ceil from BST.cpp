int findCeil(BinaryTreeNode<int> *root, int X){
    if (!root) {
        return -1;
    }
    
    if (root -> data == X) {
        return root -> data;
    }
    
    if (root -> data > X) {
        int temp = findCeil(root -> left, X);
        if (temp == -1) {
            return root -> data;
        } else {
            return min(temp, root -> data); 
        }
    }
    
    return findCeil(root -> right, X);
}
