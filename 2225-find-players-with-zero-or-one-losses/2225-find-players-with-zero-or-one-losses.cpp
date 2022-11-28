class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int> lose;
        for (auto i: matches) {
            lose[i[1]] ++;
        }
        
        unordered_set<int> vis;
        vector<vector<int>> ans(2);
        for (auto i: lose) {
            if (i.second == 1) {
                ans[1].push_back(i.first);
            }
        }
        
        for (auto i: matches) {
            if (lose.find(i[0]) == lose.end() && vis.find(i[0]) == vis.end()) {
                ans[0].push_back(i[0]);
                vis.insert(i[0]);
            }
        }
        
        sort(ans[0].begin(), ans[0].end());
        sort(ans[1].begin(), ans[1].end());
        return ans;
    }
};