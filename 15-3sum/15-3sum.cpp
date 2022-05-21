class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < n; i ++) {
            
            int l = i + 1;
            int r = n - 1;
            
            while (l < r) {
                if (nums[i] + nums[l] + nums[r] == 0) {
                    ans.push_back({nums[i], nums[l], nums[r]});
                    
                    while (l < r && nums[l] == nums[l + 1]) {
                        l ++;
                    }
                    
                    while (r > l && nums[r] == nums[r - 1]) {
                        r --;
                    }
                    
                    l ++;
                    r --;
                
                } else if (nums[i] + nums[l] + nums[r] < 0) {
                    l ++;
                } else {
                    r --;
                }
            }
            
            while (i < n - 2 && nums[i] == nums[i + 1 ]) {
                i ++;
            }
        }
            
        return ans;
    }
};

