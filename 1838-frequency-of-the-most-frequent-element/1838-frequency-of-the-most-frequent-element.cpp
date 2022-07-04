#define ll long long

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        vector<ll> pref(n);
        for (int i = 0; i < n; i ++) {
            if (i) pref[i] = pref[i - 1] + nums[i];
            else pref[i] = nums[i];
        }
        
        int ans = 1;
        
        for (int i = 1; i < n; i ++) {
            int l = 0;
            int r = i;
            
            while (l <= r) {
                int m = l + (r - l) / 2;
                int rem = (ll)nums[i] * ((ll)i - (ll)m) - (pref[i - 1] - pref[m] + (ll)nums[m]);
                
                if (rem > k) {
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            }
            
            ans = max(ans, i - l + 1);
        }
        
        return ans;
    }
};