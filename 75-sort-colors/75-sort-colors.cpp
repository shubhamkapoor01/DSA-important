class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int r = n - 1;
        int l = 0;
        int m = 0;
        
        while (m <= r) {
            if (nums[m] == 0) {
                swap(nums[m], nums[l]);
                l ++;
                m ++;
            
            } else if (nums[m] == 2) {
                swap(nums[m], nums[r]);
                r --;
                
            } else {
                m ++;
            }
        }
    }
};

//   r
// 1 0 2
//   m
// l
        
        
        
        