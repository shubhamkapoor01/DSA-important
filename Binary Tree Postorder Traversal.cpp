class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postorder;
        stack<TreeNode*> st;
        
        TreeNode* pre = nullptr;
        TreeNode* node = root;
        
        while (true) {
            if (node) {
                st.push(node);
                node = node -> left;

            } else {
                if (st.empty()) {
                    break;
                }
                
                TreeNode* temp = st.top();
                if (!temp -> right || pre == temp -> right) {
                    postorder.push_back(temp -> val);
                    pre = temp;
                    st.pop();
                    
                } else {
                    node = temp -> right;
                }
            }
        }
        
        return postorder;
    }
};
