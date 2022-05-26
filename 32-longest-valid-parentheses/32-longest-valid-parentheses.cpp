class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        int prev = -1;
        int curr = 0;
        int len = 0;
        
        for (int i = 0; i < n; i ++) {
            if (s[i] == '(') {
                curr ++;
                
            } else {
                if (curr == 0) {
                    prev = i;
                }
                if (curr > 0) {
                    curr --;
                }
                if (curr == 0) {
                    len = max(len, i - prev);
                }
            }
        }
        
        prev = n;
        curr = 0;
        
        for (int i = n - 1; i >= 0; i --) {
            if (s[i] == ')') {
                curr ++;
                
            } else if (curr >= 0) {
                if (curr == 0) {
                    prev = i;
                }
                if (curr > 0) {
                    curr --;
                }
                if (curr == 0) {
                    len = max(len, prev - i);
                }
            }
        }
        
        return len;
    }
};
    