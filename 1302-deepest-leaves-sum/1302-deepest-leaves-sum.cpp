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
    void solve(TreeNode* root, int& sum, int& maxdepth, int currdepth) {
        if (!root) {
            return;
        }
        
        if (currdepth > maxdepth) {
            sum = root -> val;
            maxdepth = currdepth;
            
        } else if (currdepth == maxdepth) {
            sum += root -> val;
        }
        
        solve(root -> left, sum, maxdepth, currdepth + 1);
        solve(root -> right, sum, maxdepth, currdepth + 1);
        return;
    }
    
public:
    int deepestLeavesSum(TreeNode* root) {
        int sum = 0;
        int depth = 0;
        solve(root, sum, depth, 0);
        return sum;
    }
};