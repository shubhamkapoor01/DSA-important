#define ll long long 

class Solution{
    public:
    int maxLen(vector<int> &v, int n) {  
        unordered_map<ll, ll> m;
        int ans = 0;
        m[0] = -1;
        ll sum = 0;
        
        for (ll i = 0; i < n; i ++) {
            sum += v[i];
            
            if (m.find(sum) != m.end()) {
                ans = max((ll)(ans), i - m[sum]);
                
            } else {
                m[sum] = i;
            }
        }
        return ans;
    }
};
