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
    void flatten(TreeNode* root) {
        if (!root) {
            return;
        }
        
        flatten(root -> left);
        flatten(root -> right);
        
        TreeNode* leftChild = root -> left;
        TreeNode* rightChild = root -> right;
        
        TreeNode* temp = root;
        temp -> right = leftChild;
        temp -> left = nullptr;
        
        while (temp && temp -> right) {
            temp = temp -> right;
        }
        
        temp -> right = rightChild;
        return;
    }
};