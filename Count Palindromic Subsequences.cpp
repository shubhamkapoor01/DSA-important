class Solution {
    private:
    int mod;
    
    long long int solve(string& str, int l, int r, vector<vector<int>>& dp) {
        if (l > r) {
            return 0;
        }
        
        if (l == r) {
            return 1;
        }
        
        if (dp[l][r] != -1) {
            return dp[l][r];
        }
        
        if (str[l] == str[r]) {
            dp[l][r] = (1 + (solve(str, l + 1, r, dp) % mod + solve(str, l, r - 1, dp) % mod) % mod) % mod;
        } else {
            dp[l][r] = ((solve(str, l + 1, r, dp) % mod + solve(str, l, r - 1, dp) % mod) % mod - solve(str, l + 1, r - 1, dp) % mod + mod) % mod;
        }
        
        return dp[l][r];
    }
    
    public:
    long long int countPS(string str) {
        int n = str.size();
        this -> mod = 1000000007;
        vector<vector<int>> dp(n, vector<int> (n, -1));
        return solve(str, 0, n - 1, dp) % mod;
    }
};
