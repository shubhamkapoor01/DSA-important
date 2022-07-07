class Solution {
public:
//     bool solve(string& s1, string& s2, string& s3, int i, int j) {
//         if (i == s1.size() && j == s2.size()) return true;
        
//         if (dp[i][j] != -1) return dp[i][j];
        
//         if (s1[i] == s3[i + j] && s2[j] == s3[i + j]) {
//             return dp[i][j] = solve(s1, s2, s3, i + 1, j) || solve(s1, s2, s3, i, j + 1);
            
//         } else if (s1[i] == s3[i + j]) {
//             return dp[i][j] = solve(s1, s2, s3, i + 1, j);
        
//         } else if (s2[j] == s3[i + j]) {
//             return dp[i][j] = solve(s1, s2, s3, i, j + 1);
            
//         } else {
//             return dp[i][j] = false;
//         }
//     }
    
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size();
        int m = s2.size();
        int k = s3.size();
        
        if (k != n + m) return false;
        
        vector<int> dp(m + 1, false);
        
        for (int i = 0; i <= n; i ++) {
            for (int j = 0; j <= m; j ++) {
                if (i == 0 && j == 0) {
                    dp[j] = true;
                    
                } else if (i > 0 && j > 0) {
                    dp[j] = (dp[j] && s1[i - 1] == s3[i + j - 1]) || (dp[j - 1] && s2[j - 1] == s3[i + j - 1]);
                    
                } else if (i > 0) {
                    dp[j] = (dp[j] && s1[i - 1] == s3[i + j - 1]);
                
                } else if (j > 0) {
                    dp[j] = (dp[j - 1] && s2[j - 1] == s3[i + j - 1]);
                
                } else {
                    dp[j] = false;
                }
            }
        }
        
        return dp[m];
    }
};