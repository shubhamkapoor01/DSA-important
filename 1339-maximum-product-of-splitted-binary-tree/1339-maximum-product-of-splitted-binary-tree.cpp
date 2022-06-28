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
    int MakeRootChildSum(TreeNode* root) {
        if (!root) return 0;
        int left = MakeRootChildSum(root -> left);
        int right = MakeRootChildSum(root -> right);
        root -> val += left + right;
        return root -> val;
    }
    
    void calcAns(TreeNode* root, TreeNode* treeRoot, long long& ans) {
        if (!root) return;
        
        if (root -> left) {
            ans = max(ans, (long long)root -> left -> val * ((long long)treeRoot -> val - (long long)root -> left -> val));
        }
        
        if (root -> right) {
            ans = max(ans, (long long)root -> right -> val * ((long long)treeRoot -> val - (long long)root -> right -> val));
        }
        
        calcAns(root -> left, treeRoot, ans);
        calcAns(root -> right, treeRoot, ans);
        return;
    }
    
    int maxProduct(TreeNode* root) {
        long long ans = 0;
        MakeRootChildSum(root);
        calcAns(root, root, ans);
        return ans % 1000000007;
    }
};