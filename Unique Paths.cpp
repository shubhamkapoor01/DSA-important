// MATH
class Solution {
public:
    
    int uniquePaths(int m, int n) {
        vector<long double> fac;
        fac.push_back(1);
        
        for (int i = 1; i <= m + n - 2; i ++) {
            fac.push_back(i * fac[i - 1]);
        }
        
        return fac[m + n - 2] / (fac[m - 1] * fac[n - 1]);
    }
};

// DP
class Solution {
public:
    int solve(int m, int n, int i, int j, vector<vector<int>> &dp) {
        if (i == m - 1 && j == n - 1) {
            return 1;
        }
        
        if (i >= m || j >= n) {
            return 0;
        }
        
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        
        dp[i][j] = solve(m, n, i + 1, j, dp) + solve(m, n, i, j + 1, dp);
        return dp[i][j];
    }
    
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int> (n + 1, -1));
        return solve(m, n, 0, 0, dp);
    }
};
