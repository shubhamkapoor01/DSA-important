class Solution {
public:
    bool solve(TreeNode* root, long low, long high) {
        if (!root) {
            return true;
        }
        
        if (root -> val <= low || root -> val >= high) {
            return false;
        }
        
        return solve(root -> left, low, root -> val) && solve(root -> right, root -> val, high);
    }
    
    bool isValidBST(TreeNode* root) {
        return solve(root, LONG_MIN, LONG_MAX);
    }
};
