class Solution {
public:
    int maxProduct(vector<string>& word) {
        int n = word.size();
        int len = 0;
        
        vector<vector<int>> freq(n, vector<int> (26, 0));
        
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < word[i].size(); j ++) {
                freq[i][word[i][j] - 'a'] ++;
            }
        }
        
        for (int i = 0; i < n - 1; i ++) {
            for (int j = i + 1; j < n; j ++) {
                bool possible = true;
                
                for (int k = 0; k < 26; k ++) {
                    if (freq[i][k] > 0 && freq[j][k] > 0) {
                        possible = false;
                        break;
                    }
                }
                
                if (possible) {
                    len = max(len, (int)word[i].size() * (int)word[j].size());
                }
            }
        }
        
        return len;
    }
};