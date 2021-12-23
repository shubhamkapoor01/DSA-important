class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        bool done = false;
        
        for (int i = nums.size() - 1; i > 0; i --) {
            if (nums[i] > nums[i - 1]) {
                
                int j = i;
                while (j < nums.size() && nums[j] > nums[i - 1]) {
                    j ++;
                }
                j --;
                
                int t = nums[i - 1];
                nums[i - 1] = nums[j];
                nums[j] = t;
                
                reverse(nums.begin() + i, nums.end());
                done = true;
                break;
            }
        }
        
        if (!done) {
            reverse(nums.begin(), nums.end());
        }
        return;
    }
};