class Solution {
private:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> lis;
        lis.push_back(nums[0]);
        
        for (int i = 1; i < n; i ++) {
            if (nums[i] >= lis[lis.size() - 1]) {
                lis.push_back(nums[i]);
                
            } else {
                int ub = upper_bound(lis.begin(), lis.end(), nums[i]) - lis.begin();
                
                if (ub < lis.size()) {
                    if (ub == 0) {
                        lis[ub] = nums[i];
                        
                    } else if (lis[ub - 1] <= nums[i]) {
                        lis[ub] = nums[i];
                    }
                }
            }
        }
        
        return lis.size();
    }
    
public:
    int kIncreasing(vector<int>& arr, int k) {
        int n = arr.size();
        vector<vector<int>> ans(k);
        for (int i = 0; i < k; i ++) {
            for (int j = i; j < n; j += k) {
                ans[i].push_back(arr[j]);
            }
        }
        
        int cnt = 0;
        for (int i = 0; i < k; i ++) {
            cnt += ans[i].size() - lengthOfLIS(ans[i]);
        }
        
        return cnt;
    }
};

// 4 1 5 2 6 2;

// 4 2;
// 1 6;
// 5 2;

