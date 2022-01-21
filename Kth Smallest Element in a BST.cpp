class Solution {
public:
    void solve(TreeNode* root, int k, int &i, int &x) {
        if (!root) {
            return;
        }
        
        solve(root -> left, k, i, x);
        
        i ++;
        if (i == k) {
            x = root -> val;
            return;
        }
        
        solve(root -> right, k, i, x);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        int x, i = 0;
        solve(root, k, i, x);
        return x;
    }
};
