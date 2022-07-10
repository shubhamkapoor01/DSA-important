#define MOD 1000000007

class Solution {
private:
    int dp[5001][4][4][4];
    
    int solve(int n, int done, int a, int b, int c) {
        if (done == n) {
            return 1;
        }
        
        if (dp[done][a][b][c] != -1) {
            return dp[done][a][b][c];
        }
        
        int ans = 0;
        
        for (int i = 1; i <= 3; i ++) {
            for (int j = 1; j <= 3; j ++) {
                for (int k = 1; k <= 3; k ++) {
                    if (i == j || j == k || i == a || j == b || k == c) continue;
                    ans = (ans % MOD + solve(n, done + 1, i, j, k) % MOD) % MOD;
                }
            }
        }
        
        dp[done][a][b][c] = ans;
        return ans;
    }
    
public:
    Solution() {
        memset(dp, -1, sizeof(dp));
    }
    
    int numOfWays(int n) {
        return solve(n, 0, 0, 0, 0);
    }
};