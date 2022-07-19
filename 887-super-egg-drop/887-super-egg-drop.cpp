class Solution {
public:
    int superEggDrop(int k, int n) {
        vector<vector<int>> dp(n + 1, vector<int> (k + 1, 0));
        
        for (int i = 1; i <= n; i ++) {
            dp[i][1] = i;
        }
        
        for (int i = 1; i <= k; i ++) {
            dp[1][i] = 1;
        }
        
        for (int i = 2; i <= n; i ++) {
            for (int j = 2; j <= k; j ++) {
                int moves = 1e9;
                int r = i;
                int l = 1;
                
                while (l <= r) {
                    int m = l + (r - l) / 2;
                    
                    int breaks = dp[m - 1][j - 1];
                    int notbreaks = dp[i - m][j];
                    
                    moves = min(moves, max(breaks, notbreaks));
                    
                    if (breaks < notbreaks) {
                        l = m + 1;
                    } else {
                        r = m - 1;
                    }
                }
            
                dp[i][j] = 1 + moves;
            }
        }
        
        return dp[n][k];
    }
};