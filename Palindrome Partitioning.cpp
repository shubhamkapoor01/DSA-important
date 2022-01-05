class Solution {
public:
    bool palindrome(string s) {
        int l = 0;
        int r = s.size() - 1;
        while (l < r) {
            if (s[l] != s[r]) {
                return false;
            }
            l ++;
            r --;
        }
        return true;
    }
    
    void solve(string s, int idx, vector<vector<string>>& ans, vector<string> curr) {
        if (idx == s.size()) {
            ans.push_back(curr);
            return;
        }
        
        for (int i = idx; i < s.size(); i ++) {
            if (palindrome(s.substr(idx, i - idx + 1))) {
                curr.push_back(s.substr(idx, i - idx + 1));
                solve(s, i + 1, ans, curr);
                curr.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> curr;
        solve(s, 0, ans, curr);
        return ans;
    }
};
