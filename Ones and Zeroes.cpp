class Solution {
public:
    int solve(vector<string>& strs, int m, int n, int i, int z, int o, 
              vector<vector<vector<int>>>& dp, vector<pair<int, int>>& mp) {
        
        if (i == strs.size()) {
            return 0;
        }
        
        if (dp[i][z][o] != -1) {
            return dp[i][z][o];
        }
        
        int skip = solve(strs, m, n, i + 1, z, o, dp, mp);
        int take = 0;
            
        if (z + mp[i].first <= m && o + mp[i].second <= n) {
            take = 1 + solve(strs, m, n, i + 1, z + mp[i].first, o + mp[i].second, dp, mp);
        }
        
        dp[i][z][o] = max(skip, take);
        return dp[i][z][o];
    }
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int, int>> mp(strs.size());
        for (int i = 0; i < strs.size(); i ++) {
            int z = 0;
            int o = 0;
            
            for (int j = 0; j < strs[i].size(); j ++) {
                if (strs[i][j] == '0') {
                    z ++;
                } else {
                    o ++;
                }
            }
            
            mp[i] = {z, o};
        }
        
        vector<vector<vector<int>>> dp(strs.size() + 1, vector<vector<int>> (m + 1, vector<int> (n + 1, -1)));
        return solve(strs, m, n, 0, 0, 0, dp, mp);
    }
};
