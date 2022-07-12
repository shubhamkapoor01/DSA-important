class Solution {
private:
    int dp[501][501];
    int MOD;
    
public:
    Solution() {
        memset(dp, -1, sizeof(dp));
        MOD = 1000000007;
    }
    
    int numWays(int steps, int size, int i = 0, int pos = 0) {
        if (pos >= size || pos < 0 || steps - i < pos) {
            return 0;
        }
        
        if (i == steps) {
            return pos == 0;
        }
        
        if (dp[i][pos] != -1) {
            return dp[i][pos];
        }
        
        int ans = numWays(steps, size, i + 1, pos - 1);
        ans = (ans + numWays(steps, size, i + 1, pos + 1)) % MOD;
        ans = (ans + numWays(steps, size, i + 1, pos)) % MOD;
        
        dp[i][pos] = ans;
        return ans;
    }
};