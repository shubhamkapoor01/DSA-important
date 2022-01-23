class Solution{
public:
    int solve(int arr[], int l, int r, vector<vector<int>> &dp) {
        if (l >= r) {
            return 0;
        }
        
        if(dp[l][r] != -1) {
            return dp[l][r];
        }
        
        dp[l][r] = INT_MAX;
        
        for (int i = l; i <= r; i ++) {
            int left = solve(arr, l, i, dp);
            int right = solve(arr, i + 1, r, dp);
            int extra = arr[l - 1] * arr[i] * arr[r];
            dp[l][r] = min(dp[l][r], left + extra + right);
        }
        
        return dp[l][r];
    }

    int matrixMultiplication(int N, int arr[]) {
        vector<vector<int>> dp(N + 1, vector<int> (N + 1, -1));
        return solve(arr, 1, N - 1, dp);
    }
};
