class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int first = -1;
        int last = -1;
        
        int l = 0;
        int r = n - 1;
        
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (nums[m] >= target) {
                if (nums[m] == target) {
                    first = m;
                }
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        
        l = 0;
        r = n - 1;
        
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (nums[m] <= target) {
                if (nums[m] == target) {
                    last = m;
                }
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        
        return {first, last};
    }
};