class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder;
        stack<TreeNode*> st;
        TreeNode* node = root;
        
        while (true) {
            if (node) {
                st.push(node);
                preorder.push_back(node -> val);
                node = node -> left;
            
            } else {
                if (st.empty()) {
                    break;
                }
                
                node = st.top();
                st.pop();
                node = node -> right;
            }
        }
        
        return preorder;
    }
};
