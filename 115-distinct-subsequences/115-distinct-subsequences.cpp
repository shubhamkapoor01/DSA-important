class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        
        vector<vector<int>> dp(n + 1, vector<int> (m + 1, 0));
        for (int i = 0; i <= n; i ++) {
            dp[i][m] = 1;
        }
        
        int mod = 1000000007;
        
        for (int i = n - 1; i >= 0; i --) {
            for (int j = m - 1; j >= 0; j --) {
                dp[i][j] = dp[i + 1][j];
                if (s[i] == t[j]) {
                    dp[i][j] = (dp[i][j] % mod + dp[i + 1][j + 1] % mod) % mod;
                }
            }
        }
        
        return dp[0][0];
    }
};