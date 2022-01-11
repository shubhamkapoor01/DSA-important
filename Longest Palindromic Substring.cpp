class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        string ans;
        
        for (int i = 0; i < n; i ++) {
            int l = i - 1;
            int r = i + 1;
            
            while (l >= 0 && r < n && s[l] == s[r]) {
                l --;
                r ++;
            }
            
            l ++;
            r --;
            
            if (r - l + 1 > ans.size()) {
                ans = s.substr(l, r - l + 1);
            }
        }
        
        for (int i = 0; i < n - 1; i ++) {
            int l = i;
            int r = i + 1;
            
            while (l >= 0 && r < n && s[l] == s[r]) {
                l --;
                r ++;
            }
            
            l ++;
            r --;
            
            if (r - l + 1 > ans.size()) {
                ans = s.substr(l, r - l + 1);
            }
        }
        
        return ans;
    }
};
