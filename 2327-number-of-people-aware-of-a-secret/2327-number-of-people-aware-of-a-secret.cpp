#define ll long long
#define mod 1000000007

class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<ll> dp(n + 1, 0);
        dp[1] = 1;
        
        for (int i = 1; i <= n; i ++) {
            for (int j = i + delay; j < i + forget && j <= n; j ++) {
                dp[j] = (dp[j] % mod + dp[i] % mod) % mod;
            }
        }
        
        ll ans = 0;
        for (int i = n - forget + 1; i <= n; i ++) {
            ans = (ans % mod + dp[i] % mod) % mod;
        }
        
        return ans;
    }
};