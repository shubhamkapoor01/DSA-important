class Solution {
public:
    vector<int> createLPS(string s) {
        int n = s.size();
        vector<int> lps(n, 0);
        int idx = 0;
        
        for (int i = 1; i < n;) {
            if (s[i] == s[idx]) {
                lps[i] = idx + 1;
                idx ++;
                i ++;
                
            } else {
                if (idx == 0) {
                    lps[i] = 0;
                    i ++;
                    
                } else {
                    idx = lps[idx - 1];
                }
            }
        }
        
        return lps;
    }
    
    int strStr(string haystack, string needle) {
        if (needle == "") {
            return 0;
        }
        
        vector<int> lps = createLPS(needle);
        for (int i = 0; i < lps.size(); i ++)
            cout << lps[i] << ' ';
        cout << endl;

        int n = haystack.size();
        int m = needle.size();
        int i = 0;
        int j = 0;
        
        while (i < n) {
            if (haystack[i] == needle[j]) {
                i ++;
                j ++;
                
                if (j == m) {
                    return i - m;
                }
                continue;
            
            } else {
                while (j != 0) {
                    j = lps[j - 1];
                    
                    if (haystack[i] == needle[j]) {
                        break;
                    }
                }
                
                if (haystack[i] == needle[j]) {
                    i ++;
                    j ++;
                } else {
                    i ++;
                }
            }
        }
    
        return -1;
    }
};
