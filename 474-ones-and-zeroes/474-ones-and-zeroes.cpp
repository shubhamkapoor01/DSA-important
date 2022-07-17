class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        unordered_map<int, pair<int, int>> mp;
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
        
        vector<vector<vector<int>>> dp(strs.size() + 1, vector<vector<int>> (m + 1, vector<int> (n + 1, 0)));
        
        for (int i = 1; i <= strs.size(); i ++) {
            for (int j = 0; j <= m; j ++) {
                for (int k = 0; k <= n; k ++) {
                    dp[i][j][k] = dp[i - 1][j][k];
                    if (j >= mp[i - 1].first && k >= mp[i - 1].second) {
                        dp[i][j][k] = max(dp[i][j][k], 1 + dp[i - 1][j - mp[i - 1].first][k - mp[i - 1].second]);
                    }
                }
            }
        }
        
        return dp[strs.size()][m][n];
    }
};