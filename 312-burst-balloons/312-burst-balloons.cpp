class Solution {
public:
    int solve(vector<int>& nums, int low, int high, vector<vector<int>>& dp) {
        int ans = INT_MIN;
        int n = nums.size();
        
        if (high < low) {
            return 0;
        }
        
        if (high == low) {
            return nums[low - 1] * nums[low] * nums[high + 1];
        }
        
        if (dp[low][high] != -1) {
            return dp[low][high];
        }
        
        for (int i = low; i <= high; i ++) {
            int curr = nums[low - 1] * nums[i] * nums[high + 1];
            
            dp[low][i - 1] = solve(nums, low, i - 1, dp);
            dp[i + 1][high] = solve(nums, i + 1, high, dp);
            
            ans = max(ans, dp[low][i - 1] + curr + dp[i + 1][high]);
        }
        
        dp[low][high] = ans;
        return ans;
    }
    
    int maxCoins(vector<int>& nums) {
        vector<vector<int>> dp(nums.size() + 2, vector<int> (nums.size() + 2, -1));
        
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        
        return solve(nums, 1, nums.size() - 2, dp);
    }
};