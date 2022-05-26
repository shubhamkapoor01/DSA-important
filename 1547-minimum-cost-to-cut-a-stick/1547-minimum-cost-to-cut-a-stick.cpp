class Solution {
private:
    int solve(vector<int>& cuts, int l, int r, int start, int end, vector<vector<int>>& dp) {
        if (l > r) {
            return 0;
        }
        
        if (dp[l][r] != -1) {
            return dp[l][r];
        }
        
        int answer = 1e9;
        
        for (int i = l; i <= r; i ++) {
            int left = solve(cuts, l, i - 1, start, cuts[i], dp);
            int right = solve(cuts, i + 1, r, cuts[i], end, dp);;
            answer = min(answer, left + right + end - start);
        }
        
        dp[l][r] = answer;
        return answer;
    }
    
public:
    int minCost(int len, vector<int>& cuts) {
        sort(cuts.begin(), cuts.end());
        int n = cuts.size();
        vector<vector<int>> dp(n, vector<int> (n, -1));
        return solve(cuts, 0, n - 1, 0, len, dp);
    }
};