class Solution{
	public:
	int solve(int coins[], int m, int v, int i, vector<vector<int>> &dp) {
	    if (v == 0) {
	        return 0;
	    }
	    
	    if (v < 0 || i >= m) {
	        return 1e9;
	    }
	    
	    if (dp[v][i] != -1) {
	        return dp[v][i];
	    }
	    
	    int option1 = solve(coins, m, v, i + 1, dp);
	    int option2 = 1 + solve(coins, m, v - coins[i], i, dp);
	    
	    dp[v][i] = min(option1, option2);
	    return dp[v][i];
	}
	
	int minCoins(int coins[], int M, int V) {
	    vector<vector<int>> dp(V + 1, vector<int> (M + 1, -1));
	    int ans = solve(coins, M, V, 0, dp);
	    if (ans >= 1e9) {
	        return -1;
	    } else {
	        return ans;
	    }
	}
};
