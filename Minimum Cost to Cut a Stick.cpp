class Solution {
public:
    int solve(vector<int>& cuts, int l, int r, vector<vector<int>>& dp) {
        if (l + 1 >= r) {
            return 0;
        }
        
        if (dp[l][r] != -1) {
            return dp[l][r];
        }
        
        int minCost = 1e9;
        
        for (int i = l + 1; i < r; i ++) {
            int left = solve(cuts, l, i, dp);
            int right = solve(cuts, i, r, dp);
            int currCost = cuts[r] - cuts[l];
            minCost = min(minCost, left + currCost + right);
        }
        
        dp[l][r] = minCost;
        return minCost;
    }
    
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        
        vector<vector<int>> dp(cuts.size() + 1, vector<int> (cuts.size() + 1, -1));
        return solve(cuts, 0, cuts.size() - 1, dp);
    }
};
