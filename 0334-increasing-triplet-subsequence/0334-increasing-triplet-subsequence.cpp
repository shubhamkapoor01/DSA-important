class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        vector<int> LIS;
        for (auto &i: nums) {
            if (!LIS.size() || i > LIS.back()) {
                LIS.push_back(i);
                if (LIS.size() == 3) {
                    return true;
                }
            } else {
                int idx = lower_bound(LIS.begin(), LIS.end(), i) - LIS.begin();
                LIS[idx] = i;
            }
        }
        return false;
    }
};