class Solution {
private:
    bool solve(string& s, int i, vector<int>& dp, vector<string>& words) {
        if (i == s.size()) {
            return true;
        }
        
        if (dp[i] != -1) {
            return dp[i];
        }
        
        bool ans = false;
        
        for (auto &word: words) {
            if (word == s.substr(i, word.size())) {
                ans |= solve(s, i + word.size(), dp, words);
            }
        }
        
        dp[i] = ans;
        return ans;
    }
    
public:
    bool wordBreak(string s, vector<string>& words) {
        int n = s.size();
        vector<int> dp(n, -1);
        return solve(s, 0, dp, words);
    }
};