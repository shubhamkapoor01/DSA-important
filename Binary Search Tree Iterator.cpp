class BSTIterator {
    TreeNode* root;
    vector<TreeNode*> st;
    
    void pushLeft(TreeNode* root) {
        TreeNode* curr = root;
        
        while (curr) {
            st.push_back(curr);
            curr = curr -> left;
        }
    }
    
public:
    BSTIterator(TreeNode* root) {
        this -> root = root;
        pushLeft(root);
    }
    
    int next() {
        TreeNode* ans = st[st.size() - 1];        
        st.pop_back();
        pushLeft(ans -> right);
        return ans -> val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};
