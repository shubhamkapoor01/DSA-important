class Solution {
private:
    bool palindrome(string s) {
        int i = 0;
        int j = s.size() - 1;
        while (i < j) {
            if (s[i] != s[j]) {
                return false;
            }
            i ++;
            j --;
        }
        return true;
    }
    
    void solve(string& s, int i, vector<string>& curr, vector<vector<string>>& ans) {
        if (i == s.size()) {
            ans.push_back(curr);
            return;
        }
        
        for (int j = i; j < s.size(); j ++) {
            if (palindrome(s.substr(i, j - i + 1))) {
                curr.push_back(s.substr(i, j - i + 1));
                solve(s, j + 1, curr, ans);
                curr.pop_back();
            }
        }
    }
    
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> curr;
        solve(s, 0, curr, ans);
        return ans;
    }
};