class Solution {
public:
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        TreeNode* curr = root;
        
        while (curr) {
            if (!curr -> left) {
                inorder.push_back(curr -> val);
                curr = curr -> right;
                
            } else {
                TreeNode* prev = curr -> left;
                while (prev -> right && prev -> right != curr) {
                    prev = prev -> right;
                }
                
                if (!prev -> right) {
                    prev -> right = curr;
                    curr = curr -> left;
                
                } else {
                    prev -> right = nullptr;
                    inorder.push_back(curr -> val);
                    curr = curr -> right;
                }
            }
        }
        
        return inorder;
    }
};
