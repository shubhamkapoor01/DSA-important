#define ll long long

class Solution {
public:
    ll minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        ll m = robot.size();
        ll n = factory.size();
        ll MAX = 1e15;
        vector<vector<ll>> dp(m+1, vector<ll>(n+1, MAX));
        
        dp[0][0] = 0;
        for (ll j = 1; j <= n; ++j) dp[0][j] = 0;
        
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());
        
        for (ll j = 1; j <= n; ++j) {
            ll f = factory[j-1][0], d = factory[j-1][1];
            for (ll i = 1; i <= m; ++i) {
                dp[i][j] = dp[i][j-1];
                
                ll subtotal = 0;
                for (ll k = 1; k <= min(d, i); ++k) {
                    subtotal += llabs((ll)f - robot[i-k]);
                    dp[i][j] = min(dp[i][j], dp[i-k][j-1] + subtotal);
                }
            }
        }
        
        ll res = MAX;
        for (ll j = 1; j <= n; ++j) {
            res = min(res, dp[m][j]);
        }
        
        return res;
    }
};