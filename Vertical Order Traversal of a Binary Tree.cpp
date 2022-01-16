class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> mp;
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0, 0}});
        
        while (!q.empty()) {
            TreeNode* node = q.front().first;
            int lvl = q.front().second.first;
            int row = q.front().second.second;
            q.pop();
            
            mp[lvl][row].insert(node -> val);
            
            if (node -> left) {
                q.push({node -> left, {lvl - 1, row + 1}});
            }
            
            if (node -> right) {
                q.push({node -> right, {lvl + 1, row + 1}});
            }
        }
        
        vector<vector<int>> vertical;
        
        for (auto i: mp) {
            vector<int> currLvl;
            
            for (auto j: i.second) {
                currLvl.insert(currLvl.end(), j.second.begin(), j.second.end());
            }
            vertical.push_back(currLvl);
        }
        
        return vertical;
    }
};
