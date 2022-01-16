bool getPath(TreeNode* root, int B, vector<int> &ans) {
    if (!root) {
        return false;
    }
    
    ans.push_back(root -> val);
    if (root -> val == B) {
        return true;
    }
    
    bool left = getPath(root -> left, B, ans);
    if (left) {
        return true;
    }
    
    bool right = getPath(root -> right, B, ans);
    if (right) {
        return true;
    }
    
    ans.pop_back();
    return false;
}
 
vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int> ans;
    if (getPath(A, B, ans)) {
        return ans;
    } else {
        return {-1};
    }
}
