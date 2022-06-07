class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        
        vector<int> prev(m + 1, 0);
        vector<int> curr(m + 1, 0);
        
        prev[m] = 1;
        curr[m] = 1;
        
        int mod = 1000000007;
        
        for (int i = n - 1; i >= 0; i --) {
            for (int j = m - 1; j >= 0; j --) {
                curr[j] = prev[j];
                if (s[i] == t[j]) {
                    curr[j] = (curr[j] % mod + prev[j + 1] % mod) % mod;
                }
            }
            prev = curr;
        }
        
        return curr[0];
    }
};