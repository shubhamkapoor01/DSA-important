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
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return {};
        queue<TreeNode*> q;
        q.push(root);
        vector<int> v;
        v.push_back(root -> val);
        
        while (q.size()) {
            int n = q.size();
            bool start = false;
            
            while (n --) {
                TreeNode*  root = q.front();
                if (root -> right) {
                    q.push(root -> right);
                    if (!start) {
                        v.push_back(root -> right -> val);
                        start = true;
                    }
                }
                if (root -> left) {
                    q.push(root -> left);
                    if (!start) {
                        v.push_back(root -> left -> val);
                        start = true;
                    }
                }
                q.pop();
            }
        }
        
        return v;
    }
};