class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> level;
        if (!root) {
            return level;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            vector<int> curr;
            int n = q.size();
            
            while (n --) {
                TreeNode* front = q.front();
                curr.push_back(front -> val);
                q.pop();
                
                if (front -> left) {
                    q.push(front -> left);
                }
                if (front -> right) {
                    q.push(front -> right);
                }
            }
            level.push_back(curr);
        }
        return level;
    }
};
