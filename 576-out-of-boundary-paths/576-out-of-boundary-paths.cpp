class Solution {
private:
    int dp[51][51][51];
    int mod;

    int solve(int n, int m, int move, int r, int c) {
        if (move < 0) {
            return 0;
        }
        
        if (r < 0 || c < 0 || r == n || c == m) {
            return 1;
        }
        
        if (dp[move][r][c] != -1) {
            return dp[move][r][c];
        }
        
        int ans = solve(n, m, move - 1, r + 1, c);
        ans = (ans + solve(n, m, move - 1, r - 1, c)) % mod;
        ans = (ans + solve(n, m, move - 1, r, c + 1)) % mod;
        ans = (ans + solve(n, m, move - 1, r, c - 1)) % mod;
        
        dp[move][r][c] = ans;
        return ans;
    }
    
public:
    Solution() {
        memset(dp, -1, sizeof(dp));
        mod = 1000000007;
    }
    
    int findPaths(int n, int m, int move, int r, int c) {
        return solve(n, m, move, r, c);
    }
};