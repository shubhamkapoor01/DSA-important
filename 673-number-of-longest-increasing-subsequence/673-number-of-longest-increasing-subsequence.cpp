class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> lis(n, 1);
        vector<int> cnt(n, 1);
        
        for (int i = 1; i < n; i ++) {
            for (int j = 0; j < i; j ++) {
                if (nums[j] < nums[i]) {
                    if (lis[i] < lis[j] + 1) {
                        lis[i] = lis[j] + 1;
                        cnt[i] = cnt[j];
                    } else if (lis[i] - 1 == lis[j]) {
                        cnt[i] += cnt[j];
                    }
                }
            }
        }
        
        int mx = *max_element(lis.begin(), lis.end());
        int tot = 0;
        
        for (int i = 0; i < n; i ++) {
            if (lis[i] == mx) {
                tot += cnt[i];
            }
        }
        
        return tot;
    }
};