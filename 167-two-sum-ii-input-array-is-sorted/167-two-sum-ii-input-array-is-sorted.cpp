class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> v;
        int r = n - 1;
        int l = 0;
        while (l <= r) {
            if (nums[l] + nums[r] == target) {
                return {l + 1, r + 1};
            } else if (nums[l] + nums[r] < target) {
                l ++;
            } else {
                r --;
            }
        }
        return {-1, -1};
    }
};