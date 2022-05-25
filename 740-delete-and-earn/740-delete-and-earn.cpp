class Solution {
private:
    int solve(vector<int>& nums, int idx, vector<int>& dp) {
        if (idx == nums.size()) {
            return 0;
        }
        
        if (dp[idx] != -1) {
            return dp[idx];
        }
        
        int total = 0;
        int curr = idx;
        
        while (curr < nums.size() && nums[curr] == nums[idx]) {
            total += nums[idx];
            curr ++;
        }
        
        int next = curr;
        while (next < nums.size() && nums[next] == nums[idx] + 1) {
            next ++;
        }
        
        int option1 = total + solve(nums, next, dp);
        int option2 = solve(nums, curr, dp);
        
        dp[idx] = max(option1, option2);
        return dp[idx];
    }
    
public:
    int deleteAndEarn(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> dp(n, -1);
        return solve(nums, 0, dp);
    }
};