class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int r = n - 1;
        int l = 0;
        
        while (l <= r) {
            int m = l + (r - l) / 2;
            
            if (nums[m] == target) {
                return m;
            }
            
            if (nums[m] > nums[r]) {
                if (nums[m] > target && target > nums[r]) {
                    r = m - 1;
                } else {
                    l = m + 1;
                }
                
            } else {
                if (nums[m] < target && target <= nums[r]) {
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            }
        }
        
        return -1;
    }
};