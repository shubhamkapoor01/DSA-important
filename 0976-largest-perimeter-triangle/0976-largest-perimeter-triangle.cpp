class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        int n = nums.size();
        int i = 0;
        int j = 1;
        int k = 2;
        while (k < n) {
            if (nums[i] < nums[j] + nums[k]) {
                return nums[i] + nums[j] + nums[k];
            } else {
                i ++;
                j ++;
                k ++;
            }
        }
        return false;
    }
};