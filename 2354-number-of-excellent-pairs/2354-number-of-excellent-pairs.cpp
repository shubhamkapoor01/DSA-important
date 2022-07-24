#define ll long long

class Solution {
public:
    ll countExcellentPairs(vector<int>& nums, int k) {
        ll n = nums.size();
        ll ans = 0;
        
        vector<ll> bucket(32);
        unordered_set<ll> st;
        
        for (auto &i: nums) {
            if (st.count(i)) continue;
            st.insert(i);
            
            int bits = 0;
            while (i) {
                bits += (i & 1);
                i /= 2;
            }
            
            if (2 * bits >= k) ans ++;
            
            for (ll j = 0; j < 32; j ++) {
                if (j + bits >= k) {
                    ans += 2 * bucket[j];
                }
            }
                
            bucket[bits] ++;
        }
        return ans;
    }
};