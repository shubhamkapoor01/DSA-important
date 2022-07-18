class Solution {
private:
    int solve(vector<int>& coins, int i, int amount, vector<vector<int>>& dp) {
        if (i == coins.size()) {
            return amount ? 1e9 : 0;
        }
        
        if (dp[i][amount] != -1) {
            return dp[i][amount];
        }
        
        dp[i][amount] = solve(coins, i + 1, amount, dp);
        if (amount >= coins[i]) {
            dp[i][amount] = min(dp[i][amount], 1 + solve(coins, i, amount - coins[i], dp)); 
        }
              
        return dp[i][amount];
    }
    
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int> (amount + 1, -1));
        int ans = solve(coins, 0, amount, dp);
        return ans == 1e9 ? -1 : ans;
    }
};

