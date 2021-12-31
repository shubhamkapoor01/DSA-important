#define ll long long

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        vector<vector<int>> ans;
        
        for (int i = 0; i < n - 3; i ++) {
            for (int j = i + 1; j < n - 2; j ++) {
                int l = j + 1;
                int r = n - 1;
                
                while (l < r) {
                    if ((ll)nums[i] + (ll)nums[j] + (ll)nums[l] + (ll)nums[r] == (ll)target) {
                        ans.push_back({nums[i], nums[j], nums[l], nums[r]});
                        l ++;
                        r --;
                        
                        while (l < r && nums[l] == nums[l - 1]) {
                            l ++;
                        }
                        
                        while (l < r && nums[r] == nums[r + 1]) {
                            r --;
                        }
                        
                    } else if ((ll)nums[i] + (ll)nums[j] + (ll)nums[l] + (ll)nums[r] < (ll)target) {
                        l ++;
                    } else {
                        r --;
                    }
                }
                
                while (j < n - 2 && nums[j + 1] == nums[j]) {
                    j ++;
                }
            }
            
            while (i < n - 3 && nums[i + 1] == nums[i]) {
                i ++;
            }
        }
        
        return ans;
    }
};
