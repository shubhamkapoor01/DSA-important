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
public:
    int pseudoPalindromicPaths(TreeNode* root, int mask = 0) {
        if (!root) {
            return 0;
        }
        
        mask ^= (1 << (root -> val));
        
        if (!root -> left && !root -> right) {
            return (mask & (mask - 1)) == 0;
        }
        
        int left = pseudoPalindromicPaths(root -> left, mask);
        int right = pseudoPalindromicPaths(root -> right, mask);
        
        return left + right;
    }
};