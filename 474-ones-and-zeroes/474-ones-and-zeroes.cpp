class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int, int>> mp(strs.size());
        
        for (int i = 0; i < strs.size(); i ++) {
            int o = 0;
            int z = 0;
            for (auto &j: strs[i]) {
                if (j == '1') {
                    o ++;
                } else {
                    z ++;
                }
            }
            mp[i] = {z, o};
        }
        
        vector<vector<int>> curr(m + 1, vector<int> (n + 1, 0));
        vector<vector<int>> prev(m + 1, vector<int> (n + 1, 0));
        
        for (int i = 1; i <= strs.size(); i ++) {
            for (int j = 0; j <= m; j ++) {
                for (int k = 0; k <= n; k ++) {
                    curr[j][k] = prev[j][k];
                    if (j >= mp[i - 1].first && k >= mp[i - 1].second) {
                        curr[j][k] = max(curr[j][k], 1 + prev[j - mp[i - 1].first][k - mp[i - 1].second]);
                    }
                }
            }
            prev = curr;
        }
        
        return curr[m][n];
    }
};