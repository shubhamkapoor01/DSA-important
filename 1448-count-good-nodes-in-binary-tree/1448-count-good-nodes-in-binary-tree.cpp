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
    void solve(TreeNode* root, int maxInPath, int& countGood) {
        if (!root) return;
        if (root -> val >= maxInPath) countGood ++;
        maxInPath = max(maxInPath, root -> val);
        solve(root -> left, maxInPath, countGood);
        solve(root -> right, maxInPath, countGood);
        return;
    }
    
public:
    int goodNodes(TreeNode* root) {
        int countGood = 0;
        solve(root, INT_MIN, countGood);
        return countGood;
    }
};