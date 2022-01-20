class Solution {
public:
    TreeNode* solve(vector<int> &preorder, int &i, int ub) {
        if (i == preorder.size() || preorder[i] > ub) {
            return nullptr;
        }
        
        TreeNode* root = new TreeNode(preorder[i ++]);
        root -> left = solve(preorder, i, root -> val);
        root -> right = solve(preorder, i, ub);
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int> &preorder) {
        int i = 0;
        return solve(preorder, i, INT_MAX);
    }
};
