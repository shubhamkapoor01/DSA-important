#define ll long long

class Solution{
    public:
    
    ll merge(ll arr[], ll temp[], ll l, ll m, ll r) {
        // cout << l << " " << m << " " << r << endl;
        
        ll i = l;
        ll j = m + 1;
        ll ans = 0;
        ll curr = l;
        
        while (i <= m && j <= r) {
            if (arr[i] <= arr[j]) {
                temp[curr ++] = arr[i ++];
            } else {
                ans += m - i + 1;
                temp[curr ++] = arr[j ++];
            }
        }
        
        while (i <= m) {
            temp[curr ++] = arr[i ++];
        }
        
        while (j <= r) {
            temp[curr ++] = arr[j ++];
        }
        
        for (ll idx = l; idx <= r; idx ++) {
            arr[idx] = temp[idx];
        }
        
        return ans;
    }
  
    ll solve(ll arr[], ll temp[], ll l, ll r) {
        ll ans = 0;
        if (l < r) {
            ll m = (l + r) / 2;
            
            ans += solve(arr, temp, l, m);
            ans += solve(arr, temp, m + 1, r);
            ans += merge(arr, temp, l, m, r);
        }
        return ans;
    }
  
    ll inversionCount(ll arr[], ll n) {
        ll temp[n];
        return solve(arr, temp, 0, n - 1);
    }
};
