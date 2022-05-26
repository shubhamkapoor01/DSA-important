class Solution {
public:
    int trap(vector<int>& nums) {
        int n = nums.size();
        int water = 0;
        int mr = 0;
        int ml = 0;
        int l = 0;
        int r = n - 1;
        
        while (l <= r) {
            ml = max(ml, nums[l]);
            mr = max(mr, nums[r]);
            
            if (nums[l] < nums[r]) {
                water += max(0, ml - nums[l]);
                l ++;
                
            } else {
                water += max(0, mr - nums[r]);
                r --;
            }
        }
        return water;
    }
};
