class Solution {
public:
    int maximalSquare(vector<vector<char>>& v) {
        int n = v.size();
        int m = v[0].size();
        
        vector<vector<int>> dp(n, vector<int> (m, 0));
        dp[0][0] = v[0][0] == '0' ? 0 : 1;
        
        for (int i = 1; i < n; i ++) {
            if (v[i][0] == '0') {
                dp[i][0] = 0;
            } else {
                dp[i][0] = 1;
            }
        }
        
        for (int j = 1; j < m; j ++) {
            if (v[0][j] == '0') {
                dp[0][j] = 0;
            } else {
                dp[0][j] = 1;
            }
        }
        
        for (int i = 1; i < n; i ++) {
            for (int j = 1; j < m; j ++) {
                if (v[i][j] == '0') {
                    continue;
                }
                
                dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
            }
        }
        
        int largest = 0;
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < m; j ++) {
                if (v[i][j] == '1') {
                    largest = max(largest, dp[i][j] * dp[i][j]);
                }
            }
        }
        
        return largest;
    }
};