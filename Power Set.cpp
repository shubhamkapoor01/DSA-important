class Solution{
public:
    void solve(string s, int i, string c, vector<string> &ans) {
        if (i == s.size()) {
            if (c != "") {
                ans.push_back(c);
            }
            return;
        }
        
        solve(s, i + 1, c, ans);
        c.push_back(s[i]);
        solve(s, i + 1, c, ans);
        return;
    }

	vector<string> AllPossibleStrings(string s) {
        vector<string> ans;
        solve(s, 0, "", ans);
        sort(ans.begin(), ans.end());
        return ans;
	}
};
