class Solution {
public:
    double solve(int n, int k, int r, int c, vector<vector<vector<vector<double>>>>& dp) {
        if (r >= n || c >= n || r < 0 || c < 0) {
            return 0;
        }
        if (k == 0) {
            return r < n && c < n && r >= 0 & c >= 0;
        }
        if (dp[n][k][r][c] != -1) {
            return dp[n][k][r][c];
        }
        vector<int> x = {1, 1, -1, -1, 2, 2, -2, -2};
        vector<int> y = {2, -2, 2, -2, 1, -1, 1, -1};
        double cnt = 0;
        for (int i = 0; i < 8; i ++) {
            int row = r + x[i];
            int col = c + y[i];
            cnt += solve(n, k - 1, row, col, dp);
        }
        return dp[n][k][r][c] = (double)cnt/(double)8;
    }
    
    double knightProbability(int n, int k, int r, int c) {
        vector<vector<vector<vector<double>>>> dp(n + 1, vector<vector<vector<double>>>(k + 1, vector<vector<double>>(n + 1, vector<double>(n + 1, -1))));
        return solve(n, k, r, c, dp);
    }
};