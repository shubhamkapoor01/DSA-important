class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int m = points[0].size();
        
        vector<long long> dp(m, 0);
        
        for (int i = 0; i < m; i ++) {
            dp[i] = points[0][i];
        }
        
        for (int i = 1; i < n; i ++) {
            vector<long long> pref(m, 0);
            vector<long long> suff(m, 0);
            
            pref[0] = dp[0];
            suff[m - 1] = dp[m - 1];
            
            for (int j = 1; j < m; j ++) {
                pref[j] = max(pref[j - 1] - 1LL, dp[j]);
            }
            
            for (int j = m - 2; j >= 0; j --) {
                suff[j] = max(suff[j + 1] - 1LL, dp[j]);
            }
            
            for (int j = 0; j < m; j ++) {
                dp[j] = points[i][j] + max(pref[j], suff[j]);
            }
        }
        
        return *max_element(dp.begin(), dp.end());
    }
};