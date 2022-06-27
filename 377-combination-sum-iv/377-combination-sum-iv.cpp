class Solution {
private:
    int solve(vector<int>& nums, int t, vector<int>& dp) {
        if (t < 0) return 0; 
        if (t == 0) return 1;
        if (dp[t] != -1) return dp[t];
        
        int ans = 0;
        for (int j = 0; j < nums.size(); j ++) {
            ans += solve(nums, t - nums[j], dp);
        }
        
        return dp[t] = ans;
    }
    
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> dp(target + 1, -1);
        return solve(nums, target, dp);
    }
};

