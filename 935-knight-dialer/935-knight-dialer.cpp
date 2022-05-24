class Solution {
private:
    int solve(int n, int i, int j, vector<vector<vector<int>>>& dp) {
        if (n == 0) {
            return 1;
        }
        
        if (dp[n][i][j] != -1) {
            return dp[n][i][j];
        }
        
        int ans = 0;
        
        vector<int> x = {1, 1, -1, -1, 2, 2, -2, -2};
        vector<int> y = {2, -2, 2, -2, 1, -1, 1, -1};
        
        for (int idx = 0; idx < 8; idx ++) {
            int row = i + x[idx];
            int col = j + y[idx];
            
            if (row < 0 || col < 0 || row > 3 || col > 2 || (row == 3 && col == 0) || (row == 3 && col == 2)) {
                continue;
            }
            
            ans = (ans + solve(n - 1, row, col, dp)) % 1000000007;
        }
        
        dp[n][i][j] = ans;
        return ans;
    }
    
public:
    int knightDialer(int n) {
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>> (4, vector<int> (3, -1)));
        int ans = 0;
        int mod = 1000000007;
        for (int i = 0; i < 3; i ++) {
            for (int j = 0; j < 3; j ++) {
                ans = (ans + solve(n - 1, i, j, dp)) % mod;
            }
        }
        ans = (ans + solve(n - 1, 3, 1, dp)) % mod;
        return ans;
    }
};