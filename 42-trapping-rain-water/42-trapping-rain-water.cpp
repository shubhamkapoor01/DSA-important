class Solution {
public:
    int trap(vector<int>& nums) {
        int n = nums.size();
        
        int water = 0;
        int rmax = 0;
        int lmax = 0;
        
        int r = n - 1;
        int l = 0;
        
        while (l < r) {
            lmax = max(lmax, nums[l]);
            rmax = max(rmax, nums[r]);
            
            if (lmax < rmax) {
                water += lmax - nums[l];
                l ++;
                
            } else {
                water += rmax - nums[r];
                r --;
            }
        }
        
        return water;
    }
};
