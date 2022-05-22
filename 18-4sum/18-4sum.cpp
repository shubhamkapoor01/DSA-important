class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> ans;
        int n = nums.size();
        
        for (int i = 0; i < n; i ++) {
            for (int j = i + 1; j < n; j ++) {
                int l = j + 1;
                int r = n - 1;
                
                while (l < r) {
                    long sum = (long)nums[i] + (long)nums[j] + (long)nums[l] + (long)nums[r];
                    
                    if (sum == target) {
                        ans.push_back({nums[i], nums[j], nums[l], nums[r]});
                        
                        while (l < r && nums[l] == nums[l + 1]) l ++;
                        while (r > l && nums[r] == nums[r - 1]) r --;
                        l ++;
                        r --;
                    
                    } else if (sum > target) {
                        r --;
                    } else {
                        l ++;
                    }
                }
                
                while (j + 1 < n && nums[j] == nums[j + 1]) j ++;
            }
            
            while (i + 1 < n && nums[i] == nums[i + 1]) i ++;
        }
        
        return ans;
    }
};