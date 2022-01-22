class Solution {
public:    
    int minDistance(string p, string q) {
        int n = p.size();
        int m = q.size();
        vector<vector<int>> dp(n + 1, vector<int> (m + 1, 0));
        
        for (int i = 0; i <= n; i ++) {
            dp[i][0] = i;
        }
        
        for (int i = 0; i <= m; i ++) {
            dp[0][i] = i;
        }
        
        for (int i = 1; i <= n; i ++) {
            for (int j = 1; j <= m; j ++) {
                dp[i][j] = dp[i - 1][j - 1];
                
                if (p[i - 1] != q[j - 1]) {
                    dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
                    
                }
            }
        }
        
        return dp[n][m];
    }
};
