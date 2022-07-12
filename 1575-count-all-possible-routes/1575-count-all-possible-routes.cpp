class Solution {
public:
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        int n = locations.size();
        int dp[n][fuel + 1];
        int MOD = 1000000007;
        
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i <= fuel; i ++) {
            dp[finish][i] = 1;
        }
        
        for (int j = 1; j <= fuel; j ++) {
            for (int i = 0; i < n; i ++) {
                int ans = (i == finish);
                for (int k = 0; k < n; k ++) {
                    if (i != k && j >= abs(locations[i] - locations[k])) {
                        ans = (ans + dp[k][j - abs(locations[i] - locations[k])]) % MOD;
                    }
                }
                dp[i][j] = ans;
            }
        }
        
        return dp[start][fuel];
    }
};