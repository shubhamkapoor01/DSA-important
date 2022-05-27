class Solution {
public:
    int superEggDrop(int k, int n) {
        // dp[moves][k] -> how many floors at max can we solve the question for
        // when we have maximum "moves" moves to use and k eggs to throw from
        // moves can be n in worst case hence dp with n + 1 rows is used here
        vector<vector<int>> dp(n + 1, vector<int> (k + 1, 0));
        
        int moves = 0;
        while (dp[moves][k] < n) {
            moves ++;
            
            for (int i = 1; i <= k; i ++) {
                // dp[moves - 1][i - 1] -> when egg breaks we check below the 
                // current floor with i - 1 eggs and moves - 1 remaining moves
                dp[moves][i] += dp[moves - 1][i - 1];
                
                // dp[moves - 1][i] -> when egg does not break, we check above
                // the current floor with i eggs and moves - 1 remaining moves
                dp[moves][i] += dp[moves - 1][i];
                
                // 1 is added to cunt the current floor the egg is thrown from
                dp[moves][i] += 1;
            }
        }
        
        return moves;
    }
};