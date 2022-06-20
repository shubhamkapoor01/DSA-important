class Solution {
private:
    vector<int> getLPS(string& s, int m) {
        vector<int> lps(m, 0);
        int prev = 0;
        int curr = 1;
        
        while (curr < m) {
            if (s[prev] == s[curr]) {
                lps[curr] = prev + 1;
                curr ++;
                prev ++;
                
            } else {
                if (prev) {
                    prev = lps[prev - 1];
                    
                } else {
                    lps[curr] = 0;
                    curr ++;
                }
            }
        }
    
        return lps;
    }
    
public:
    string shortestPalindrome(string s) {
        if (s == "") return "";
        
        string ans = s;
        string r = s;
        reverse(r.begin(), r.end());
        s = s + "$" + r;
        
        int n = s.size();
        vector<int> lps = getLPS(s, n);
        
        return r.substr(0, n / 2 - lps[n - 1]) + ans;
    }
};