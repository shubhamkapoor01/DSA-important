class Solution {
public:
    string removeOccurrences(string s, string p) {
        int n = s.size();
        int m = p.size();
        
        if (n < m) {
            return s;
        }
        
        for (int i = 0; i < n - m + 1; i ++) {
            if (s.substr(i, m) == p) {
                return removeOccurrences(s.substr(0, i) + s.substr(i + m), p);
            }
        }
        
        return s;
    }
};