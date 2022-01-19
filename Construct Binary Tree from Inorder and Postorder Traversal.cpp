class Solution {
public:
    TreeNode* solve(int is, int ie, int ps, int pe, vector<int> &inorder, 
                    vector<int> &postorder, unordered_map<int, int> &mp) {
        
        if (is > ie || ps > pe) {
            return nullptr;
        }
        
        TreeNode* root = new TreeNode(postorder[pe]);
        int inRoot = mp[root -> val];
        int lsize = inRoot - is;
        
        root -> left = solve(is, inRoot - 1, ps, ps + lsize - 1, inorder, postorder, mp);
        root -> right = solve(inRoot + 1, ie, ps + lsize, pe - 1, inorder, postorder, mp);
            
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> mp;
        for (int i = 0; i < inorder.size(); i ++) {
            mp[inorder[i]] = i;
        }
        return solve(0, inorder.size() - 1, 0, postorder.size() - 1, inorder, postorder,  mp);
    }
};
