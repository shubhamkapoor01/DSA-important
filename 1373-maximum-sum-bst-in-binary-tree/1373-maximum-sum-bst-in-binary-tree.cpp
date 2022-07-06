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
    vector<int> solve(TreeNode* root, int& mx) {
        if (!root) return {0, INT_MAX, INT_MIN, 1};
        
        if (!root -> left && !root -> right) {
            return {root -> val, root -> val, root -> val, 1};
        }
        
        vector<int> left = solve(root -> left, mx);
        vector<int> right = solve(root -> right, mx);
        
        if (left[3]) {
            mx = max(mx, left[0]);
        }
        
        if (right[3]) {
            mx = max(mx, right[0]);
        }
        
        if (left[2] < root -> val && right[1] > root -> val && left[3] && right[3]) {
            mx = max(mx, root -> val + left[0] + right[0]);
            return {root -> val + left[0] + right[0], min(root -> val, left[1]), max(root -> val, right[2]), 1};
        }
        
        return {root -> val, root -> val, root -> val, 0};
    }
    
public:
    int maxSumBST(TreeNode* root) {
        int mx = 0;
        vector<int> v = solve(root, mx);
        return mx;
    }
};