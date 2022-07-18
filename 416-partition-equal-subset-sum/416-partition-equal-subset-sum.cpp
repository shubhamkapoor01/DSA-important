class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        
        for (int i = 0; i < n; i ++) {
            sum += nums[i];
        }
        
        if (sum % 2) return false;
        sum /= 2;
        
        vector<bool> dp(sum + 1, 0);
        dp[0] = true;
        
        for (int i = 1; i <= n; i ++) {
            for (int j = sum; j >= 1; j --) {
                if (j >= nums[i - 1]) {
                    dp[j] = dp[j] | dp[j - nums[i - 1]];
                }
            }
        }
        
        return dp[sum];
    }
};