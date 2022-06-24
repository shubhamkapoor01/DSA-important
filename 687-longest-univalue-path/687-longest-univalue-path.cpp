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
    int solve(TreeNode* root, int curr, int& optimal) {
        if (!root) {
            return 0;
        }
        
        int left = solve(root -> left, curr, optimal);
        int right = solve(root -> right, curr, optimal);
        
        int rootAnsLeft = (root -> left && root -> val == root -> left -> val) ? left + 1 : 0;
        int rootAnsRight = (root -> right && root -> val == root -> right -> val) ? right + 1 : 0;
        
        optimal = max({optimal, rootAnsLeft + rootAnsRight + 1});
        return max(rootAnsLeft, rootAnsRight);
    }
    
public:
    int longestUnivaluePath(TreeNode* root) {
        if (!root) return 0;
        int optimal = 0;
        int rootAns = solve(root, 0, optimal);
        return optimal - 1;
    }
};