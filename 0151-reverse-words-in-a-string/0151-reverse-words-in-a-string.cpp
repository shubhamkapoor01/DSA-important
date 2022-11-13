class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        
        for (int i = s.size() - 1; i >= 0; i --) {
            while (i >= 0 && s[i] == ' ') {
                i --;
            }
            
            if (i < 0) {
                break;
            }
            
            while (i >= 0 && s[i] != ' ') {
                ans.push_back(s[i]);
                i --;
            }
            ans.push_back(' ');
        }
        
        for (int i = 0; i < ans.size(); i ++) {
            if (ans[i] == ' ') {
                continue;
            }
            
            int j = i;
            while (j < ans.size() && ans[j] != ' ') {
                j ++;
            }
            
            int l = i;
            int r = j;
            
            while (l < r) {
                swap(ans[l], ans[r]);
                l ++;
                r --;
            }
            
            i = j;
        }
        
        return ans.substr(1);
    }
};