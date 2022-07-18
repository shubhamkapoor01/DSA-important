class Solution {
// private:
//     int solve(vector<int>& coins, int i, int amount, vector<vector<int>>& dp) {
//         if (i == coins.size()) {
//             return amount ? 1e9 : 0;
//         }
        
//         if (dp[i][amount] != -1) {
//             return dp[i][amount];
//         }
        
//         dp[i][amount] = solve(coins, i + 1, amount, dp);
//         if (amount >= coins[i]) {
//             dp[i][amount] = min(dp[i][amount], 1 + solve(coins, i, amount - coins[i], dp)); 
//         }
              
//         return dp[i][amount];
//     }
    
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        
        vector<vector<int>> dp(n + 1, vector<int> (amount + 1, 1e9));
        for (int i = 0; i <= n; i ++) {
            dp[i][0] = 0;
        }
        
        for (int i = 1; i <= n; i ++) {
            for (int j = 1; j <= amount; j ++) {
                dp[i][j] = dp[i - 1][j];
                if (j >= coins[i - 1]) {
                    dp[i][j] = min(dp[i][j], 1 + dp[i][j - coins[i - 1]]);
                }
            }
        }
            
        return dp[n][amount] == 1e9 ? -1 : dp[n][amount];
    }
};

