class Solution {
private:
    int dp[20001][6];
    
public:
    Solution() {
        memset(dp, -1, sizeof(dp));
    }
    
    int countVowelPermutation(int n, int prev = 0) {
        if (!n) {
            return 1;
        }
        
        if (dp[n][prev] != -1) {
            return dp[n][prev];
        }
        
        int ans = 0;
        
        if (prev == 0) {
            ans = (ans + countVowelPermutation(n - 1, 1)) % 1000000007;
            ans = (ans + countVowelPermutation(n - 1, 2)) % 1000000007;
            ans = (ans + countVowelPermutation(n - 1, 3)) % 1000000007;
            ans = (ans + countVowelPermutation(n - 1, 4)) % 1000000007;
            ans = (ans + countVowelPermutation(n - 1, 5)) % 1000000007;
        }
                
        if (prev == 1) {
            ans = (ans + countVowelPermutation(n - 1, 2)) % 1000000007;
        }
                
        if (prev == 2) {
            ans = (ans + countVowelPermutation(n - 1, 1)) % 1000000007;
            ans = (ans + countVowelPermutation(n - 1, 3)) % 1000000007;
        }
                
        if (prev == 3) {
            ans = (ans + countVowelPermutation(n - 1, 1)) % 1000000007;
            ans = (ans + countVowelPermutation(n - 1, 2)) % 1000000007;
            ans = (ans + countVowelPermutation(n - 1, 4)) % 1000000007;
            ans = (ans + countVowelPermutation(n - 1, 5)) % 1000000007;
        }
                
        if (prev == 4) {
            ans = (ans + countVowelPermutation(n - 1, 3)) % 1000000007;
            ans = (ans + countVowelPermutation(n - 1, 5)) % 1000000007;
        }
                
        if (prev == 5) {
            ans = (ans + countVowelPermutation(n - 1, 1)) % 1000000007;
        }
        
        dp[n][prev] = ans;
        return ans;
    }
};