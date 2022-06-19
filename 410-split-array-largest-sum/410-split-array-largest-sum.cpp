class Solution {
private:
    bool possible(vector<int>& nums, int k, int m) {
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < n; i ++) {
            if (nums[i] > m) {
                return false;
            }
            sum += nums[i];
            if (sum > m) {
                sum = nums[i];
                k --;
            }
        }
        if (sum) {
            k --;
        }
        return k >= 0;
    }
    
public:
    int splitArray(vector<int>& nums, int k) {
        int ans = 0;
        int l = 0;
        int r = 0;
        for (auto &num: nums) {
            r += num;
        }
        
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (possible(nums, k, m)) {
                r = m - 1;
                ans = m;
            } else {
                l = m + 1;
            }
        }
        
        return ans;
    }
};