class Solution {
private:
    void solve(string& s, int idx, string& curr, vector<string>& ans, vector<string>& wordDict) {
        if (idx == s.size()) {
            curr.pop_back();
            ans.push_back(curr);
            return;
        }
        
        for (auto &word: wordDict) {
            if (idx + word.size() <= s.size() && s.substr(idx, word.size()) == word) {
                string t = curr;
                curr += word;
                curr.push_back(' ');
                solve(s, idx + word.size(), curr, ans, wordDict);
                curr = t;
            }
        }
    }
    
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> ans;
        string curr;
        solve(s, 0, curr, ans, wordDict);
        return ans;
    }
};