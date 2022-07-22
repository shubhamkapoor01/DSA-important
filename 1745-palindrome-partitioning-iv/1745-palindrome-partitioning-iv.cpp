class Solution {
public:
    bool checkPartitioning(string& s) {
        int n = s.size();
        
        vector<vector<bool>> dp(n, vector<bool> (n, true));
        
        for (int gap = 1; gap < n; gap ++) {
            for (int i = 0; i + gap < n; i ++) {
                int j = i + gap;
                dp[i][j] = (s[i] == s[j]) && dp[i + 1][j - 1];
            }
        }
        
        for (int i = 0; i < n - 2; i ++) {
            for (int j = i + 1; j < n - 1; j ++) {
                if (dp[0][i] && dp[i + 1][j] && dp[j + 1][n - 1]) {
                    return true;
                }
            }
        }
        
        return false;
    }
};