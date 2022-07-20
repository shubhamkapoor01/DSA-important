class Solution {
public:
    int numMatchingSubseq(string& s, vector<string>& words) {
        vector<vector<int>> v(26);
        for (int i = 0; i < s.size(); i ++) {
            v[s[i] - 'a'].push_back(i);
        }
        
        int ans = 0;
        
        for (int i = 0; i < words.size(); i ++) {
            int subsequence = 1;
            int idx = 0;
            
            for (int j = 0; j < words[i].size(); j ++) {
                int key = words[i][j] - 'a';    
                int next = lower_bound(v[key].begin(), v[key].end(), idx) - v[key].begin();
                
                
                
                if (next == v[key].size()) {
                    subsequence = 0;
                    break;
                    
                } else {
                    idx = v[key][next] + 1;
                }
            }
            
            if (subsequence) {
                ans ++;
            }
        }
        
        return ans;
    }
};