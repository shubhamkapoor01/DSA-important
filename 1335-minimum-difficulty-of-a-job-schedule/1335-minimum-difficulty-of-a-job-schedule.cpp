class Solution {
private:
    int solve(vector<int>& jobs, int i, int d, int mx, vector<vector<vector<int>>>& dp) {
        if (i == jobs.size()) {
            return d == 0 ? mx : 1e9;
        }
        
        if (dp[i][d][mx] != -1) {
            return dp[i][d][mx];
        }
        
        int option1 = solve(jobs, i + 1, d, max(mx, jobs[i]), dp);
        int option2 = 1e9;
        if (d > 0) {
            option2 = max(mx, jobs[i]) + solve(jobs, i + 1, d - 1, 0, dp);
        }
        
        dp[i][d][mx] = min(option1, option2);
        return dp[i][d][mx];
    }
    
public:
    int minDifficulty(vector<int>& jobs, int d) {
        int n = jobs.size();
        
        if (n < d) {
            return -1;
        }
        
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>> (d + 1, vector<int> (1001, -1)));
        return solve(jobs, 0, d, 0, dp);
    }
};