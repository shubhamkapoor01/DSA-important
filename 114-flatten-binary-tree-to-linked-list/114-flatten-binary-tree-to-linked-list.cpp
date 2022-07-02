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
    pair<TreeNode*, TreeNode*> solve(TreeNode* root) {
        if (!root || (!root -> left && !root -> right)) {
            return {root, root};
        }
        
        pair<TreeNode*, TreeNode*> leftList = solve(root -> left);
        pair<TreeNode*, TreeNode*> rightList = solve(root -> right);
        
        root -> left = nullptr;
        
        if (!rightList.first) {
            root -> right = leftList.first;
            return {root, leftList.second};
        }
        
        if (leftList.first) {
            root -> right = leftList.first;
            leftList.second -> right = rightList.first;
        } else {
            root -> right = rightList.first;
        }
        
        return {root, rightList.second};
    }
    
public:
    void flatten(TreeNode* root) {
        root = solve(root).first;
        return;
    }
};