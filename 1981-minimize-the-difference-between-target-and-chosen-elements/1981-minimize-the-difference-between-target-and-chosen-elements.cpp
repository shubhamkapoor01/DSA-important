class Solution {
private:
    int n, m;
    
    int solve(vector<vector<int>>& mat, int i, int t, int targ, vector<vector<int>>& dp) {
        if (i == n) {
            return abs(t - targ);
        }
        
        if (dp[i][t] != -1) {
            return dp[i][t];
        }
        
        if (t >= targ) {
            dp[i][t] = solve(mat, i + 1, t + *min_element(mat[i].begin(), mat[i].end()), targ, dp);
            return dp[i][t];
        }
        
        int diff = INT_MAX;
        
        for (int j = 0; j < m; j ++) {
            diff = min(diff, solve(mat, i + 1, t + mat[i][j], targ, dp));
        }
        
        dp[i][t] = diff;
        return diff;
    }
    
public:
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        n = mat.size();
        m = mat[0].size();
        vector<vector<int>> dp(n + 1, vector<int> (5000, -1));
        return solve(mat, 0, 0, target, dp);
    }
};