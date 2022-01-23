class Solution {
public:
    int solve(vector<int>& coins, int idx, int amt, vector<vector<int>>& dp) {
        if (amt == 0) {
            return 0;
        }
        
        if (idx == coins.size()) {
            return 1e6;
        }
        
        if (dp[idx][amt] != -1) {
            return dp[idx][amt];
        }
        
        int skip = solve(coins, idx + 1, amt, dp);
        int take = INT_MAX;
        
        if (amt >= coins[idx]) {
            take = 1 + solve(coins, idx, amt - coins[idx], dp);
        }
        
        dp[idx][amt] = min(skip, take);
        return dp[idx][amt];
    }
    
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int> (amount + 1, -1));
        int ans = solve(coins, 0, amount, dp);
        return ans == 1e6 ? -1 : ans;
    }
};
