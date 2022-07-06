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
        if (!root) return {0, INT_MAX, INT_MIN};
        
        if (!root -> left && !root -> right) {
            mx = max(mx, root -> val);
            return {root -> val, root -> val, root -> val};
        }
        
        vector<int> left = solve(root -> left, mx);
        vector<int> right = solve(root -> right, mx);
        
        if (!left.size() || !right.size() || left[2] >= root -> val || right[1] <= root -> val) {
            return {};
        }
        
        mx = max(mx, root -> val + left[0] + right[0]);
        return {root -> val + left[0] + right[0], min(left[1], root -> val), max(right[2], root -> val)};
    }
    
public:
    int maxSumBST(TreeNode* root) {
        int mx = 0;
        vector<int> t = solve(root, mx);
        return mx;
    }
};