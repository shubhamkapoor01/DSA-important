class Solution {
private:
    unordered_map<int, pair<int, int>> mp;
    
    int solve(int i, int cm, int cn, int m, int n, vector<vector<vector<int>>>& dp) {
        if (i == mp.size()) {
            return 0;
        }
        
        if (dp[i][cm][cn] != -1) {
            return dp[i][cm][cn];
        }
        
        int ans = solve(i + 1, cm, cn, m, n, dp);
        
        if (mp[i].first + cm <= m && mp[i].second + cn <= n) {
            ans = max(ans, 1 + solve(i + 1, cm + mp[i].first, cn + mp[i].second, m, n, dp));
        }
        
        dp[i][cm][cn] = ans;
        return ans;
    }
    
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<vector<int>>> dp(strs.size() + 1, vector<vector<int>> (m + 1, vector<int> (n + 1, -1)));
        for (int i = 0; i < strs.size(); i ++) {
            int o = 0;
            int z = 0;
            for (auto &j: strs[i]) {
                if (j == '1') o ++;
                else z ++;
            }
            mp[i] = {z, o};
        }
        return solve(0, 0, 0, m, n, dp);
    }
};