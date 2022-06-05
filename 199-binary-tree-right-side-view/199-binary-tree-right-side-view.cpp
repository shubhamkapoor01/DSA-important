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
    void solve(TreeNode* root, int currDepth, int& maxDepth, unordered_map<int, int>& mp) {
        if (!root) return;
        maxDepth = max(maxDepth, currDepth);
        if (mp.find(currDepth) == mp.end()) mp[currDepth] = root -> val;
        solve(root -> right, currDepth + 1, maxDepth, mp);
        solve(root -> left, currDepth + 1, maxDepth, mp);
        return;
    }
    
public:
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return {};
        unordered_map<int, int> mp;
        int h = 0;
        solve(root, 0, h, mp);
        vector<int> v(h + 1);
        for (auto &i: mp) {
            v[i.first] = i.second;
        }
        return v;
    }
};