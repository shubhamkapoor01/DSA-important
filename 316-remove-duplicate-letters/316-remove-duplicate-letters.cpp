class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.size();
        vector<int> last(26);
        for (int i = 0; i < n; i ++) {
            last[s[i] - 'a'] = i;
        }
        
        vector<int> vis(26, 0);
        string str;
        
        for (int i = 0; i < n; i ++) {
            if (vis[s[i] - 'a']) {
                continue;
            }
            
            while (str.size() && last[str.back() - 'a'] > i && str.back() > s[i]) {
                vis[str.back() - 'a'] = 0;
                str.pop_back();
            }
            
            str.push_back(s[i]);
            vis[s[i] - 'a'] = 1;
        }
        
        return str;
    }
};




