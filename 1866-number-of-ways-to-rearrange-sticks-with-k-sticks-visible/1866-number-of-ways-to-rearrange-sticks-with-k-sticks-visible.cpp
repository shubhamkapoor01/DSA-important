#define mod 1000000007

class Solution {
public:
    int rearrangeSticks(int n, int k) {
        vector<vector<long>> dp(n + 1, vector<long> (k + 1, 0));
        dp[0][0] = 1;
        
        for (int i = 1; i <= n; i ++) {
            for (int j = 1; j <= min(i, k); j ++) {
                dp[i][j] = ((i - 1) % mod * dp[i - 1][j] % mod) % mod;
                dp[i][j] = (dp[i][j] % mod + dp[i - 1][j - 1] % mod) % mod;
            }
        }
        
        return dp[n][k];
    }
};