class Solution {
private:
    int solve(vector<int>& nums, int i, int t) {
        if (i == nums.size()) {
            return !t;
        }
        
        return solve(nums, i + 1, t + nums[i]) + solve(nums, i + 1, t - nums[i]);
    }
    
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(nums, 0, target);
    }
};