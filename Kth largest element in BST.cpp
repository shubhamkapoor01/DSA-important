class Solution {
    public:
    void solve(Node* root, int k, int &i, int &x) {
        if (!root) {
            return;
        }
        
        solve(root -> right, k, i, x);
        
        i ++;
        if (i == k) {
            x = root -> data;
            return;
        }
        
        solve(root -> left, k, i, x);
    }

    int kthLargest(Node *root, int k) {
        int x, i = 0;
        solve(root, k, i, x);
        return x;
    }
};
