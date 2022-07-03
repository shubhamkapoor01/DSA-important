class Solution {
private:
    int solve(vector<int>& stone, int l, int r, vector<int>& sum, vector<vector<int>>& dp) {
        if (l >= r) {
            return 0;
        }
        
        if (dp[l][r] != -1) {
            return dp[l][r];
        }
        
        int ans = 0;
        
        for (int i = l; i < r; i ++) {
            int leftsum = sum[i] - sum[l] + stone[l];
            int rightsum = sum[r] - sum[i];
            
            if (leftsum < rightsum) {
                ans = max(ans, leftsum + solve(stone, l, i, sum, dp));
                
            } else if (leftsum > rightsum) {
                ans = max(ans, rightsum + solve(stone, i + 1, r, sum, dp));
                
            } else {
                ans = max(ans, leftsum + solve(stone, l, i, sum, dp));
                ans = max(ans, rightsum + solve(stone, i + 1, r, sum, dp));
            }
        }
        
        dp[l][r] = ans;
        return ans;
    }
    
public:
    int stoneGameV(vector<int>& stone) {
        int n = stone.size();
        vector<int> sum(n, 0);
        for (int i = 0; i < n; i ++) {
            if (i) sum[i] = sum[i - 1] + stone[i];
            else sum[i] = stone[i];
        } 
        vector<vector<int>> dp(n, vector<int> (n, -1));
        return solve(stone, 0, n - 1, sum, dp);
    }
};