class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> curr(amount + 1, 1e9);
        curr[0] = 0;
        
        for (int i = 1; i <= n; i ++) {
            for (int j = 1; j <= amount; j ++) {
                if (j >= coins[i - 1]) {
                    curr[j] = min(curr[j], 1 + curr[j - coins[i - 1]]);
                }
            }
        }
        
        return curr[amount] != 1e9 ? curr[amount] : -1;
    }
};

