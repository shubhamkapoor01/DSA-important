class Solution {
private:
    vector<int> getLPS(string& p) {
        int m = p.size();
        vector<int> lps(m);
        
        int i = 1;
        int j = 0;
        
        while (i < p.size()) {
            if (p[i] == p[j]) {
                lps[i] = j + 1;
                i ++;
                j ++;
                
            } else {
                if (j) {
                    j = lps[j - 1];
                    
                } else {
                    lps[i] = 0;
                    i ++;
                }
            }
        }
        
        return lps;
    }
    
    bool KMP(string& s, string& p) {
        int n = s.size();
        int m = p.size();
        
        vector<int> lps = getLPS(p);
        
        int i = 0;
        int j = 0;
        
        while (i < n && j < m) {
            if (s[i] == p[j]) {
                i ++;
                j ++;
                
                if (j == m) {
                    return true;
                }
            
            } else {
                if (j) {
                    j = lps[j - 1];
                    
                } else {
                    i ++;
                }
            }
        }
        
        return false;
    }
    
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int cnt = 0;
        for (auto pattern: patterns) {
            if (KMP(word, pattern)) {
                cnt ++;
            }
        }
        return cnt;
    }
};