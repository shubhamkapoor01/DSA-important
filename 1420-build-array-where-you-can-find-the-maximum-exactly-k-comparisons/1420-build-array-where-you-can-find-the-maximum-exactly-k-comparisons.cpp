class Solution {
private:
    int dp[51][101][51];
    int mod;
    
public:
    Solution() {
        memset(dp, -1, sizeof(dp));
        mod = 1000000007;
    }
    
    int solve(int n, int mx, int k, int m) {
        if (k < 0) {
            return 0;
        }
        
        if (!n) {
            return !k;
        }
        
        if (dp[n][mx][k] != -1) {
            return dp[n][mx][k];
        }
        
        int ans = 0;
        
        for (int i = 1; i <= m; i ++) {
            if (i > mx) {
                ans = (ans + solve(n - 1, i, k - 1, m)) % mod;
            } else {
                ans = (ans + solve(n - 1, mx, k, m)) % mod;
            }
        }
        
        return dp[n][mx][k] = ans;
    }
    
    int numOfArrays(int n, int m, int k) {
        return solve(n, 0, k, m);
    }
};