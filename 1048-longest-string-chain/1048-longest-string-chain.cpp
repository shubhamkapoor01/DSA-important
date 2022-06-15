class Solution {
public:
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        unordered_map<string, int> dp;
            
        sort(words.begin(), words.end(), []
            (const string& first, const string& second) {
                return first.size() < second.size();
            });
        
        int lsc = 1;
        for (int i = 0; i < n; i ++) {
            dp[words[i]] = 1;
            for (int j = 0; j < words[i].size(); j ++) {
                string predecessor = words[i].substr(0, j) + words[i].substr(j + 1);
                if (dp.find(predecessor) != dp.end()) {
                    dp[words[i]] = max(dp[words[i]], 1 + dp[predecessor]);
                }
            }
            lsc = max(lsc, dp[words[i]]);
        }
        
        return lsc;
    }
};