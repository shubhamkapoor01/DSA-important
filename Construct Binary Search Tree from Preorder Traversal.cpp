class Solution {
public:
    TreeNode* solve(int is, int ie, int ps, int pe, vector<int> &inorder, 
                    vector<int> &preorder, map<int, int> &mp) {
        
        if (is > ie || ps > pe) {
            return nullptr;
        }
        
        TreeNode* root = new TreeNode(preorder[ps]);
        int inRoot = mp[root -> val];
        int lsize = inRoot - is;
        
        root -> left = solve(is, inRoot - 1, ps + 1, ps + lsize, inorder, preorder, mp);
        root -> right = solve(inRoot + 1, ie, ps + lsize + 1, pe, inorder, preorder, mp);
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int> &preorder) {
        vector<int> inorder = preorder;
        sort(inorder.begin(), inorder.end());
        
        map<int, int> mp;
        for (int i = 0; i < inorder.size(); i ++) {
            mp[inorder[i]] = i;
        }
        
        return solve(0, inorder.size() - 1, 0, preorder.size() - 1, inorder, preorder, mp);
    }
};
