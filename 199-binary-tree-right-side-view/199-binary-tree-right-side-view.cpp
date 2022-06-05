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
    void solve(TreeNode* root, int currDepth, vector<int>& v) {
        if (!root) return;
        if (v.size() == currDepth) v.push_back(root -> val);
        solve(root -> right, currDepth + 1, v);
        solve(root -> left, currDepth + 1, v);
        return;
    }
    
public:
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return {};
        vector<int> v;
        solve(root, 0, v);
        return v;
    }
};