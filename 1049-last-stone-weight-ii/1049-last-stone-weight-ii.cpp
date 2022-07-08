class Solution {
// private:
//     int solve(vector<int>& stones, int i, int s, int sum, vector<vector<int>>& dp) {
//         if (i == stones.size()) {
//             return abs(sum - 2 * s);
//         }
        
//         if (dp[i][s] != -1) {
//             return dp[i][s];
//         }
        
//         int ans = solve(stones, i + 1, s, sum, dp);
//         ans = min(ans, solve(stones, i + 1, s + stones[i], sum, dp));
        
//         dp[i][s] = ans;
//         return ans;
//     }
    
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        int sum = 0;
        for (auto i: stones) {
            sum += i;
        }
        
        vector<vector<int>> dp(n + 1, vector<int> (sum + 1, 0));
        
        for (int i = 0; i <= n; i ++) {
            for (int s = 0; s <= sum; s ++) {
                if (i == 0) {
                    dp[i][s] = abs(sum - 2 * s);
                } else {
                    dp[i][s] = min(dp[i - 1][s], ((s - stones[i - 1] >= 0) ? dp[i - 1][s - stones[i - 1]] : 1000000));
                }
            }
        }
        
        return dp[n][sum];
    }
};