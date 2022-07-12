class Solution {
private:
    int dp[101][201];
    int MOD;
    
    int solve(vector<int>& locations, int curr, int finish, int fuel) {
        if (fuel < 0) {
            return 0;
        }
        
        if (dp[curr][fuel] != -1) {
            return dp[curr][fuel];
        }
        
        int ans = (curr == finish);
        
        for (int i = 0; i < locations.size(); i ++) {
            if (i != curr) {
                ans = (ans + solve(locations, i, finish, fuel - abs(locations[i] - locations[curr]))) % MOD;
            }
        }
        
        dp[curr][fuel] = ans;
        return ans;
    }
    
public:
    Solution() {
        memset(dp, -1, sizeof(dp));
        MOD = 1e9 + 7;
    }
    
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        return solve(locations, start, finish, fuel);
    }
};