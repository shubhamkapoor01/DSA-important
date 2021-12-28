class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        
        for (int i = n - 1; i > 0; i --) {
            if (nums[i - 1] < nums[i]) {
                int j = i;
                while ( j < n && nums[j] > nums[i - 1]) {
                    j ++;
                }
                j --;
                int temp = nums[j];
                nums[j] = nums[i - 1];
                nums[i - 1] = temp;
                reverse(nums.begin() + i, nums.end());
                return;
            }
        }
        
        reverse(nums.begin(), nums.end());
        return;
    }
};
