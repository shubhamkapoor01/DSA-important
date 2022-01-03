class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        
        for (int i = 0; i < n - 2; i ++) {
            int l = i + 1;
            int r = n - 1;
            
            while (l < r) {
                if (nums[i] + nums[l] + nums[r] == 0) {
                    ans.push_back({nums[i], nums[l], nums[r]});
                    int t1 = nums[l];
                    int t2 = nums[r];
                    while (l < r && nums[l] == t1) {
                        l ++;
                    }
                    while (r > l && nums[r] == t2) {
                        r --;
                    }
                    
                } else if (nums[i] + nums[l] + nums[r] > 0) {
                    int temp = nums[r];
                    while (r > l && nums[r] == temp) {
                        r --;
                    }
                    
                } else {
                    int temp = nums[l];
                    while (l < r && nums[l] == temp) {
                        l ++;
                    }
                }
            }
            
            int temp = nums[i];
            while (i < n - 3 && nums[i + 1] == temp) {
                i ++;
            }
        }
        
        return ans;
    }
};
