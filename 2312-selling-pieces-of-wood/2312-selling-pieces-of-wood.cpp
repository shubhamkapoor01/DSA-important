#define ll long long

class Solution {
public:
    long long sellingWood(int n, int m, vector<vector<int>>& prices) {
        vector<vector<ll>> dp(n + 1, vector<ll> (m + 1, 0));
        
        for (int i = 0; i < prices.size(); i ++) {
            dp[prices[i][0]][prices[i][1]] = max(dp[prices[i][0]][prices[i][1]], (ll)prices[i][2]);
        }
        
        for (int i = 1; i <= n; i ++) {
            for (int j = 1; j <= m; j ++) {
                for (int k = 1; k <= i; k ++) {
                    dp[i][j] = max(dp[i][j], dp[i - k][j] + dp[k][j]);
                }
                for (int k = 1; k <= j; k ++) {
                    dp[i][j] = max(dp[i][j], dp[i][j - k] + dp[i][k]);
                }
            }
        }
        
        return dp[n][m];
    }
};