class Solution {
public:
    pair<int, bool> solve(TreeNode* root) {
        if (!root) {
            return {0, true};
        }
        
        pair<int, bool> left = solve(root -> left);
        pair<int, bool> right = solve(root -> right);
        
        if (abs(left.first - right.first) > 1) {
            return {max(left.first, right.first) + 1, false};
        } else {
            return {max(left.first, right.first) + 1, left.second && right.second};
        }
    }
    
    bool isBalanced(TreeNode* root) {
        return solve(root).second;
    }
};
