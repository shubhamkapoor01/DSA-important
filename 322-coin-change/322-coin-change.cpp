class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        
        vector<int> dp(amount + 1, 1e9);
        dp[0] = 0;
        
        for (int i = 1; i <= n; i ++) {
            for (int j = 1; j <= amount; j ++) {
                if (j >= coins[i - 1]) {
                    dp[j] = min(dp[j], 1 + dp[j - coins[i - 1]]);
                }
            }
        }
            
        return dp[amount] == 1e9 ? -1 : dp[amount];
    }
};

