class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        int n = nums.size();
        
        while (l <= r) {
            int m = l + (r - l) / 2;
            
            if (nums[m] == target) {
                return m;
            }
            
            if ((m == n - 1) || (m + 1 < n && nums[m] > nums[m + 1])) {
                
                if (target >= nums[0] && target < nums[m]) {
                    int lb = lower_bound(nums.begin(), nums.begin() + m, target) - nums.begin();
                    if (lb >= 0 && lb <= m && nums[lb] == target) {
                        return lb;
                    }
                }

                if (m + 1 < n && target <= nums[n - 1] && target >= nums[m + 1]) {
                    int rb = lower_bound(nums.begin() + m + 1, nums.end(), target) - nums.begin();
                    if (rb > m && rb <= n && nums[rb] == target) {
                        return rb;
                    }
                }

                return -1;
            }
            
            if (nums[l] <= nums[m]) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        
        return -1;
    }
};
