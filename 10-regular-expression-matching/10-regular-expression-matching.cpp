class Solution {
private:
    bool valid(string& p, int j) {
        j ++;
        
        if (j == p.size() || p.back() != '*') {
            return false;
        }
        
        while (j < p.size()) {
            if (p[j] != '*') {
                return false;
            }
            j += 2;
        }
        
        return true;
    }
    
    bool solve(string& s, string& p, int i, int j, vector<vector<int>>& dp) {
        if (i == s.size() && j == p.size()) {
            return true;
        }
        
        if (j == p.size()) {
            return false;
        }
        
        if (i == s.size()) {
            return valid(p, j);
        }
        
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        
        if (j < p.size() - 1 && p[j + 1] == '*') {
            if (s[i] == p[j] || p[j] == '.') {
                return dp[i][j] = (solve(s, p, i + 1, j, dp) || solve(s, p, i, j + 2, dp));
            } else {
                return dp[i][j] = solve(s, p, i, j + 2, dp);
            }
        }
        
        if (s[i] == p[j] || p[j] == '.') {
            return dp[i][j] = solve(s, p, i + 1, j + 1, dp);
        }
        
        return dp[i][j] = false;
    }
    
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        
        vector<vector<int>> dp(n + 1, vector<int> (m + 1, -1));
        return solve(s, p, 0, 0, dp);
    }
};