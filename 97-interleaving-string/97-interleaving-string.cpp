class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size();
        int m = s2.size();
        int k = s3.size();
        
        if (k != n + m) return false;
        
        vector<int> curr(m + 1, false);
        
        for (int i = 0; i <= n; i ++) {
            for (int j = 0; j <= m; j ++) {
                if (i == 0 && j == 0) {
                    curr[j] = 1;
                    
                } else if (i > 0 && j > 0 && s1[i - 1] == s3[i + j - 1] && s2[j - 1] == s3[i + j - 1]) {
                    curr[j] = curr[j] | curr[j - 1];
                    
                } else if (i > 0 && s1[i - 1] == s3[i + j - 1]) {
                    curr[j] = curr[j];
                
                } else if (j > 0 && s2[j - 1] == s3[i + j - 1]) {
                    curr[j] = curr[j - 1];   
                
                } else {
                    curr[j] = false;
                }
            }
        }
        
        return curr[m];
    }
};