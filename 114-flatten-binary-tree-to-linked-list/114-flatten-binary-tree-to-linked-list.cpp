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
    TreeNode* solve(TreeNode* root) {
        if (!root) {
            return root;
        }
        
        TreeNode* leftChild = solve(root -> left);
        TreeNode* rightChild = solve(root -> right);
        
        TreeNode* temp = root;
        temp -> right = leftChild;
        temp -> left = nullptr;
        
        while (temp && temp -> right) {
            temp = temp -> right;
        }
        
        temp -> right = rightChild;
        return root;
    }
    
public:
    void flatten(TreeNode* root) {
        root = solve(root);
        return;
    }
};