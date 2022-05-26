class Solution {
private:
//     int solve(vector<int> &prices, int k, int idx, bool holding, vector<vector<vector<int>>> &dp) {
//         if (idx >= prices.size() || k <= 0) {
//             return 0;
//         }
        
//         if (dp[idx][k][holding] != -1) {
//             return dp[idx][k][holding];
//         }
        
//         if (holding) {
//             int sell = solve(prices, k - 1, idx + 1, false, dp) + prices[idx];
//             int hold = solve(prices, k, idx + 1, true, dp);
//             dp[idx][k][holding] = max(sell, hold);
//             return dp[idx][k][holding];
            
//         } else {
//             int buy = solve(prices, k, idx + 1, true, dp) - prices[idx];
//             int stay = solve(prices, k, idx + 1, false, dp);
//             dp[idx][k][holding] = max(buy, stay);
//             return dp[idx][k][holding];
//         }
//     }
    
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> prev(k + 1, vector<int> (2, 0));
        vector<vector<int>> curr(k + 1, vector<int> (2, 0));
        
        for (int i = n - 1; i >= 0; i --) {
            for (int j = 1; j <= k; j ++) {
                curr[j][1] = max(prev[j][1], prev[j][0] - prices[i]);
                curr[j][0] = max(prev[j][0], prev[j - 1][1] + prices[i]);
            }
            prev = curr;
        }
        
        return curr[k][1];
    }
};