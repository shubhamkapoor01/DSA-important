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

class Solution 
{
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) 
    {
        function<void(TreeNode*,vector<int>&)> collect;
        collect = [&](TreeNode *n, vector<int>& v)
        {
            if (n->left)               collect(n->left, v);
            if (n->right)              collect(n->right, v);
            if (!n->left && !n->right) v.push_back(n->val);
        };
        
        vector<int> vals1, vals2;
        collect(root1, vals1);
        collect(root2, vals2);
        
        return vals1 == vals2;
    }
};