class Solution {
public:    
    int superEggDrop(int K, int N) {
        vector<vector<int>> dp(N + 1, vector<int> (K + 1, 0));
        
        for (int i = 1; i <= N; i ++) {
            dp[i][0] = 1e6;
        }
        
        for (int j = 1; j <= K; j ++) {
            dp[1][j] = 1;
        }
        
        for (int n = 1; n <= N; n ++) {
            for (int k = 1; k <= K; k ++) {
                int l = 1;
                int r = n;

                while (r - l > 1) {
                    int mid = l + (r - l) / 2;
                    int doesBreak = dp[mid - 1][k - 1];
                    int notBreak = dp[n - mid][k];

                    if (doesBreak == notBreak) {
                        l = mid;
                        r = mid;

                    } else if (doesBreak > notBreak) {
                        r = mid;

                    } else {
                        l = mid;
                    }
                }
                
                dp[n][k] = 1 + min(max(dp[l - 1][k - 1], dp[n - l][k]), 
                                   max(dp[r - 1][k - 1], dp[n - r][k]));
            }
        }
        
        return dp[N][K];
    }
};
