class Solution {
private:
    int dp[21][40000];
    
    int solve(vector<int>& nums, int i, int t) {
        if (i == nums.size()) {
            return !t;
        }
        
        if (dp[i][t + 20000] != -1){ 
            return dp[i][t + 20000];
        }
        
        return dp[i][t + 20000] = solve(nums, i + 1, t + nums[i]) + solve(nums, i + 1, t - nums[i]);
    }
    
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        memset(dp, -1, sizeof(dp));
        return solve(nums, 0, target);
    }
};