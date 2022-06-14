class Solution {
private:
    int longestCommonSubsequence(string& s1, string& s2) {
        int n = s1.size();
        int m = s2.size();
        
        vector<int> prev(m + 1, 0);
        vector<int> curr(m + 1, 0);
        
        for (int i = 1; i <= n; i ++) {
            for (int j = 1; j <= m; j ++) {
                if (s1[i - 1] == s2[j - 1]) {
                    curr[j] = 1 + prev[j - 1];
                } else {
                    curr[j] = max(prev[j], curr[j - 1]);
                }
            }
            prev = curr;
        }
        
        return curr[m];
    }
    
public:
    int minDistance(string word1, string word2) {
        return word1.size() + word2.size() - 2 * longestCommonSubsequence(word1, word2);
    }
};