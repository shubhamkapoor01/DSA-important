class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<int> dp(n + 1, false);
        dp[0] = false;
        dp[1] = true;
        
        for (int i = 2; i <= n; i ++) {
            for (int j = 1; j * j <= i; j ++) {
                dp[i] |= !dp[i - j * j];
                if (dp[i]) {
                    break;
                }
            }
        }
        
        return dp[n];
    }
};