class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        
        vector<int> prev(m + 1, 0);
        vector<int> curr(m + 1, 0);
        
        curr[0] = 1;
        for (int j = 0; j <= m; j ++) {
            prev[j] = j;
        }
        
        for (int i = 1; i <= n; i ++) {
            for (int j = 1; j <= m; j ++) {
                if (word1[i - 1] == word2[j - 1]) {
                    curr[j] = prev[j - 1];
                    
                } else {
                    curr[j] = 1 + min({prev[j], curr[j - 1], prev[j - 1]});
                }
            }
            
            for (int j = 0; j <= m; j ++) {
                prev[j] = curr[j];
                curr[j] = 0;
            }
            curr[0] = i + 1;
        }
        
        return prev[m];
    }
};