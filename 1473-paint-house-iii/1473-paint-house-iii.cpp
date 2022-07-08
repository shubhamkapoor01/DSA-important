class Solution {
private:
    int dp[101][101][21];
    
    int solve(vector<int>& houses, vector<vector<int>>& cost, int idx, int target, int prev) {
        if (target < 0) {
            return 1e9;
        }
        
        if (idx == houses.size()) {
            return !target ? 0 : 1e9;
        }
        
        if (dp[idx][target][prev] != -1) {
            return dp[idx][target][prev];
        }
        
        if (houses[idx]) {
            if (houses[idx] == prev) {
                return solve(houses, cost, idx + 1, target, houses[idx]);
            } else {
                return solve(houses, cost, idx + 1, target - 1, houses[idx]);
            }
        }
        
        int ans = 1e9;
        
        for (int i = 0; i < cost[idx].size(); i ++) {
            if (i + 1 == prev) {
                ans = min(ans, cost[idx][i] + solve(houses, cost, idx + 1, target, i + 1));
            } else {
                ans = min(ans, cost[idx][i] + solve(houses, cost, idx + 1, target - 1, i + 1));
            }
        }
        
        dp[idx][target][prev] = ans;
        return ans;
    }
    
public:
    Solution() {
        memset(dp, -1, sizeof(dp));
    }
    
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        int ans = solve(houses, cost, 0, target, 0);
        return ans == 1e9 ? -1 : ans;
    }
};