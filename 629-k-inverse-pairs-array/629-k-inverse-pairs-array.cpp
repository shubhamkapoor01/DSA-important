class Solution {
public:
    int kInversePairs(int elements, int inverse) {
        vector<vector<int>> dp(elements + 1, vector<int> (inverse + 1, 0));
        for (int i = 0; i <= elements; i ++) {
            dp[i][0] = 1;
        }
        
        for (int i = 1; i <= elements; i ++) {
            for (int j = 1; j <= inverse; j ++) {
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % 1000000007;
                if (j >= i) {
                    dp[i][j] = (dp[i][j] - dp[i - 1][j - i] + 1000000007) % 1000000007;
                }
            }
        }
        
        return dp[elements][inverse];
    }
};