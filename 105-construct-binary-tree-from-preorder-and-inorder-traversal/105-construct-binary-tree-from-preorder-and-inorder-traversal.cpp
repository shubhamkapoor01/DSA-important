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
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int& curr, int l, int r, unordered_map<int, int>& idx) {
        if (l > r) {
            return nullptr;
        }

        TreeNode* root = new TreeNode(preorder[curr ++]);
        
        if (l == r) {
            return root;
        }
        
        int leftFirst = l;
        int leftLast = idx[root -> val] - 1;
        int rightFirst = idx[root -> val] + 1;
        int rightLast = r;
        
        root -> left = solve(preorder, inorder, curr, leftFirst, leftLast, idx);
        root -> right = solve(preorder, inorder, curr, rightFirst, rightLast, idx);
        return root;
    }
    
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> idx;
        for (int i = 0; i < inorder.size(); i ++) {
            idx[inorder[i]] = i;
        }
        int curr = 0;
        return solve(preorder, inorder, curr, 0, inorder.size() - 1, idx);
    }
};