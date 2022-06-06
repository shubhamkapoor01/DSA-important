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
    void solve(TreeNode* root, long target, int& rootPaths) {
        if (!(target - root -> val)) {
            rootPaths ++;
        }
        
        if (root -> left) solve(root -> left, target - root -> val, rootPaths);
        if (root -> right) solve(root -> right, target - root -> val, rootPaths);
    }
    
public:
    int pathSum(TreeNode* root, int target) {
        if (!root) return 0;
        int left = pathSum(root -> left, target);
        int right = pathSum(root -> right, target);
        int rootPaths = 0;
        solve(root, target, rootPaths);
        return left + rootPaths + right;
    }
};