class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int curr = 1;
        int mx = INT_MIN;
        for (int i = 0; i < nums.size(); i ++) {
            if (nums[i]) {
                curr *= nums[i];
                mx = max(mx, curr);
            } else {
                curr = 1;
                mx = max(mx, 0);
            }
        }
        curr = 1;
        for (int i = nums.size() - 1; i >= 0; i --) {
            if (nums[i]) {
                curr *= nums[i];
                mx = max(mx, curr);
            } else {
                curr = 1;
                mx = max(mx, 0);
            }
        }
        return mx;
    }
};