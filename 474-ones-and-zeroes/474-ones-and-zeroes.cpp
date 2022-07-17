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
        
        vector<vector<int>> dp(m + 1, vector<int> (n + 1, 0));
        
        for (int i = 0; i < strs.size(); i ++) {
            for (int j = m; j >= 0; j --) {
                for (int k = n; k >= 0; k --) {
                    if (j >= mp[i].first && k >= mp[i].second) {
                        dp[j][k] = max(dp[j][k], 1 + dp[j - mp[i].first][k - mp[i].second]);
                    }
                }
            }
        }
        
        return dp[m][n];
    }
};