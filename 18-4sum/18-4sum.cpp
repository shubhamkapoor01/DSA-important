class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        
        for (int i = 0; i < n - 3; i ++) {
            for (int j = i + 1; j < n - 2; j ++) {
                int l = j + 1;
                int r = n - 1;
                
                while (l < r) {
                    if ((long long)nums[i] + (long long)nums[j] + (long long)nums[l] + (long long)nums[r] == target) {
                        ans.push_back({nums[i], nums[j], nums[l], nums[r]});
                        
                        int newL = l + 1;
                        int newR = r - 1;
                        
                        while (newL < r && nums[newL] == nums[l]) newL ++;
                        while (newR > l && nums[newR] == nums[r]) newR --;
                        
                        l = newL;
                        r = newR;
                        
                    } else if ((long long)nums[i] + (long long)nums[j] + (long long)nums[l] + (long long)nums[r] > target) {
                        r --;
                    } else {
                        l ++;
                    }
                }
                while (j + 1 < n && nums[j + 1] == nums[j]) j ++;
            }
            while (i + 1 < n && nums[i + 1] == nums[i]) i ++;
        }
        
        return ans;
    }
};