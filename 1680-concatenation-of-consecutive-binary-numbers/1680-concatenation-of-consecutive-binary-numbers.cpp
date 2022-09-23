#define ll long long
#define mod 1000000007

ll dp[100001];

class Solution {
public:
    int concatenatedBinary(int n) {
        if (dp[n]) {
            return dp[n];
        }
        ll ans = 0;
        for (ll i = 1; i <= n; i ++) {
            ll num = i;
            vector<ll> t;
            while (num) {
                t.push_back(num & 1);
                num >>= 1;
            }
            ll j = t.size() - 1;
            while (j >= 0) {
                if (t[j] & 1) {
                    ans = (2 * ans + 1) % mod;
                } else {
                    ans = (2 * ans) % mod;
                }
                j --;
            }
            dp[i] = ans;
        }
        return ans;
    }
};