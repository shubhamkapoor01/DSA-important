class Solution {
public:
    string reorganizeString(string s) {
        vector<int> mp(26, 0);
        int n = s.size();
        
        for (auto &ch: s) {
            mp[ch - 'a'] ++;
            if (mp[ch - 'a'] > (n + 1) / 2) {
                return "";
            }
        }
        
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < 26; i ++) {
            if (mp[i]) {
                pq.push({mp[i], i});
            }
        }
        
        string ans = "";
        
        while (pq.size()) {
            pair<int, int> mx = pq.top();
            pq.pop();
            pair<int, int> smx = pq.top();
            pq.pop();
            
            if (!ans.size() || ans.back() != char('a' + mx.second)) {
                ans.push_back(char('a' + mx.second));
                ans.push_back(char('a' + smx.second));
            } else {
                ans.push_back(char('a' + smx.second));
                ans.push_back(char('a' + mx.second));
            }
            
            if (mx.first > 1) pq.push({mx.first - 1, mx.second});
            if (smx.first > 1) pq.push({smx.first - 1, smx.second});
            
            if (pq.size() == 1) {
                ans.push_back(char('a' + pq.top().second));
                break;
            }
        }
        
        return ans;
    }
};