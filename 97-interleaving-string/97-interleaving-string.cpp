class Solution {
private:
    int dp[101][201];
    
public:
    Solution() {
        memset(dp, -1, sizeof(dp));
    }
    
    bool solve(string& s1, string& s2, string& s3, int i, int j, int k) {
        if (i == s1.size() && j == s2.size()) return k == s3.size();
        if (k == s3.size()) return i == s1.size() && j == s2.size();
        if (i == s1.size()) return s2.substr(j) == s3.substr(k);
        if (j == s2.size()) return s1.substr(i) == s3.substr(k);
        
        if (dp[i][k] != -1) return dp[i][k];
        
        if (s1[i] == s3[k] && s2[j] == s3[k]) {
            return dp[i][k] = solve(s1, s2, s3, i + 1, j, k + 1) || solve(s1, s2, s3, i, j + 1, k + 1);
            
        } else if (s1[i] == s3[k]) {
            return dp[i][k] = solve(s1, s2, s3, i + 1, j, k + 1);
        
        } else if (s2[j] == s3[k]) {
            return dp[i][k] = solve(s1, s2, s3, i, j + 1, k + 1);
            
        } else {
            return dp[i][k] = false;
        }
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        return solve(s1, s2, s3, 0, 0, 0);
    }
};