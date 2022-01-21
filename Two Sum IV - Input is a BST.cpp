class Solution {
public:
    bool solve(TreeNode* root, int k, unordered_map<int, bool> &mp) {
        if (!root) {
            return false;
        }
        
        if (mp.find(k - root -> val) != mp.end()) {
            return true;
        }
        
        mp[root -> val] = true;
        return solve(root -> left, k, mp) || solve(root -> right, k, mp);
    }
    
    bool findTarget(TreeNode* root, int k) {
        unordered_map<int, bool> mp;
        return solve(root, k, mp);
    }
};
