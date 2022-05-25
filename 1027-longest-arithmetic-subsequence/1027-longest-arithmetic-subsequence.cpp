class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        int mx = 2;
        
        vector<vector<int>> dp(n + 1, vector<int> (2000, 0));
        
        for (int i = 0; i < n; i ++) {
            for (int j = i + 1; j < n; j ++) {
                int diff = nums[j] - nums[i] + 1000;
                dp[j][diff] = max(2, 1 + dp[i][diff]);
                mx = max(mx, dp[j][diff]);
            }
        }
        
        return mx;
    }
};