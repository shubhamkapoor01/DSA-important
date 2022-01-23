class Solution {
public:
    int coinChange(vector<int>& coins, int amt) {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int> (amt + 1, 0));
        
        for (int i = 0; i < amt + 1; i ++) {
            dp[0][i] = 1e6;
        }
        
        for (int i = 1; i <= n; i ++) {
            for(int j = 1; j <= amt; j ++) {
                dp[i][j] = dp[i - 1][j];
                if (j >= coins[i - 1]) {
                    dp[i][j] = min(dp[i][j], 1 + dp[i][j - coins[i - 1]]);
                }
            }
        }
        
        return dp[n][amt] != 1e6 ? dp[n][amt] : -1;
    }
};
