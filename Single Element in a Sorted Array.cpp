class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        int n = nums.size();
        
        while (l <= r) {
            int m = l + (r - l) / 2;
            int lb = m;
            int ub = m;
            
            if (m > 0 && nums[m - 1] == nums[m]) {
                lb = m - 1;
            }
            
            if (m + 1 < n && nums[m + 1] == nums[m]) {
                ub = m + 1;
            }
            
            if (lb == ub) {
                return nums[m];
            }
            
            if (lb % 2 == 1 && (n - ub + 1) % 2 == 0) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        
        return -1;
    }
};
