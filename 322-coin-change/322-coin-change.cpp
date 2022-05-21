class Solution {
private:
    int n;
    
    int solve(vector<int>& coins, int idx, int amount, vector<vector<int>>& dp) {
        if (amount == 0) {
            return 0;
        }
        
        if (idx == n) {
            return 1e9;
        }
        
        if (dp[idx][amount] != -1) {
            return dp[idx][amount];
        }
        
        int ans = 1e9;
        ans = min(ans, solve(coins, idx + 1, amount, dp));
        
        if (amount >= coins[idx]) {
            ans = min(ans, 1 + solve(coins, idx, amount - coins[idx], dp));
        }
        
        dp[idx][amount] = ans;
        return ans;
    }
    
public:
    int coinChange(vector<int>& coins, int amount) {
        n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int> (amount + 1, -1));
        int ans = solve(coins, 0, amount, dp);
        return ans != 1e9 ? ans : -1;
    }
};