/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
private:
    int solve(TreeNode* root, int& result) {
        if (!root) {
            return 0;
        }
        
        int left = solve(root -> left, result);
        int right = solve(root -> right, result);
        
        result = max(result, root -> val + left + right);
        result = max(result, root -> val + right);
        result = max(result, root -> val + left);
        result = max(result, root -> val);
        
        return max({root -> val, root -> val + left, root -> val + right});
    }
    
public:
    int maxPathSum(TreeNode* root) {
        int result = INT_MIN;
        int rootAns = solve(root, result);
        return result;
    }
};