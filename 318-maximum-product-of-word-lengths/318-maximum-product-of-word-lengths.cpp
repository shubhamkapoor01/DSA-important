class Solution {
public:
    int maxProduct(vector<string>& word) {
        int n = word.size();
        int len = 0;
        
        vector<int> bitset(n);
        
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < word[i].size(); j ++) {
                bitset[i] |= 1 << (word[i][j] - 'a');
            }
        }
        
        for (int i = 0; i < n - 1; i ++) {
            for (int j = i + 1; j < n; j ++) {
                if (bitset[i] & bitset[j]) {
                    continue;
                }
                
                len = max(len, (int)word[i].size() * (int)word[j].size());
            }
        }
        
        return len;
    }
};