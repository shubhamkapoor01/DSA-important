#define ll long long

class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        ll n = nums.size();
        ll sum = 0;
        
        for (auto &i: nums) sum += i;
        
        ll diff = 1e12;
        ll curr = 0;
        ll ans = 0;
        
        for (ll i = 0; i < n - 1; i ++) {
            curr += nums[i];
            
            ll prev = curr / (i + 1);
            ll next = (sum - curr) / (n - i - 1);
            
            if (abs(prev - next) < diff) {
                diff = abs(prev - next);
                ans = i;
            }
        }
        
        if (sum / n < diff) {
            ans = n - 1;
        }
        
        return ans;
    }
};