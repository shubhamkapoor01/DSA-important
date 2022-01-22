class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> lis;
        lis.push_back(nums[0]);
        
        for (int i = 1; i < n; i ++) {
            if (nums[i] > lis[lis.size() - 1]) {
                lis.push_back(nums[i]);
                
            } else {
                int ub = upper_bound(lis.begin(), lis.end(), nums[i]) - lis.begin();
                
                if (ub < lis.size()) {
                    if (ub == 0) {
                        lis[ub] = nums[i];
                        
                    } else if (lis[ub - 1] < nums[i]) {
                        lis[ub] = nums[i];
                    }
                }
            }
        }
        
        return lis.size();
    }
};
