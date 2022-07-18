class Solution {
public:
    int minCost(int len, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(len);
        
        sort(cuts.begin(), cuts.end());
        int n = cuts.size();
        
        vector<vector<int>> dp(n, vector<int> (n, 0));
        
        for (int gap = 2; gap < n; gap ++) {
            for (int i = 0; i + gap < n; i ++) {
                int j = i + gap;
                int ans = 1e9;
                
                for (int k = i + 1; k < j; k ++) {
                    ans = min(ans, dp[i][k] + cuts[j] - cuts[i] + dp[k][j]);
                }
                
                dp[i][j] = ans;
            }
        }
        
        return dp[0][n - 1];
    }
};