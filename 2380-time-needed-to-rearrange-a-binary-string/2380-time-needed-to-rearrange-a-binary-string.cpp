class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        int n = s.size();
        int ans = 0;
        int prev = 0;
        int prefix = 0;
        for (int i = 0; i < n; i ++) {
            if (s[i] == '1') {
                ans = max(prev, i - prefix);
                prefix ++;
                if (ans) {
                    prev = ans + 1;
                }
            }
        }
        return ans;
    }
};