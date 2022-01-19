class Solution {
public:
    int solve(TreeNode* root, int &res) {
        if (!root) {
            return -1e6;
        }
        
        int left = solve(root -> left, res);
        int right = solve(root -> right, res);
        
        res = max(res, left);
        res = max(res, right);
        res = max(res, root -> val);
        res = max(res, root -> val + left);
        res = max(res, root -> val + right);
        res = max(res, root -> val + left + right);
            
        return max(root -> val, max(left + root -> val, right + root -> val));
    }
    
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        int sol = solve(root, res);
        return res;
    }
};
