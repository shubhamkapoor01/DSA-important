class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> LIS;
        for (auto &ele: nums) {
            if (LIS.empty() || ele > LIS.back()) {
                LIS.push_back(ele);
            } else {
                int idx = lower_bound(LIS.begin(), LIS.end(), ele) - LIS.begin();
                LIS[idx] = ele;
            }
        }
        return LIS.size();
    }
};