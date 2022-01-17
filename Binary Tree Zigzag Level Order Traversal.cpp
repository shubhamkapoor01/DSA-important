class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> zigzag;
        if (!root) {
            return zigzag;
        }
        
        bool rev = false;
        queue<TreeNode*> q;
        q.push(root);

        
        while (!q.empty()) {
            vector<int> level;
            int n = q.size();
            
            while (n --) {
                TreeNode* front = q.front();
                level.push_back(front -> val);
                q.pop();
                
                if (front -> left) {
                    q.push(front -> left);
                }
                if (front -> right) {
                    q.push(front -> right);
                }
            }
            
            if (rev) {
                reverse(level.begin(), level.end());
                rev = false;
            } else {
                rev = true;
            }
            
            zigzag.push_back(level);
        }
        
        return zigzag;
    }
};
