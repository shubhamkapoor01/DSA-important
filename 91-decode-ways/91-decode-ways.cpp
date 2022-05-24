class Solution {
private:
    int solve(string& s, int idx, vector<int>& dp) {
        if (idx == s.size()) {
            return 1;
        }
        
        if (dp[idx] != -1) {
            return dp[idx];
        }
        
        int ans = 0;
        
        if ((s[idx] - '0') != 0) {
            ans += solve(s, idx + 1, dp);
        }
        
        if (idx + 1 < s.size() && (s[idx] - '0') != 0 && (s[idx] - '0') * 10 + (s[idx + 1] - '0') <= 26) {
            ans += solve(s, idx + 2, dp);
        }
        
        dp[idx] = ans;
        return ans;
    }
    
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n, -1);
        return solve(s, 0, dp);
    }
};