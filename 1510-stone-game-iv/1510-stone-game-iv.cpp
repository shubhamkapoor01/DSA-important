class Solution {
private:
    int alice, bob;
    
public:
    Solution() {
        this -> alice = 1;
        this -> bob = 0;
    }
    
    bool winnerSquareGame(int n) {
        vector<vector<int>> dp(n + 1, vector<int> (2, 0));
        dp[0][alice] = bob;
        dp[0][bob] = alice;
        dp[1][alice] = alice;
        dp[1][bob] = bob;
        
        for (int i = 2; i <= n; i ++) {
            for (int j = 1; j * j <= i; j ++) {
                dp[i][alice] |= dp[i - j * j][bob];
                dp[i][bob] |= !dp[i - j * j][alice];
                
                if (dp[i][alice] && dp[i][bob]) {
                    break;
                }
            }
            dp[i][bob] = !dp[i][bob];
        }
        
        return dp[n][alice];
    }
};