class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        int length = 0;
        int prev = -1;
        int curr = 0;
        
        for (int i = 0; i < n; i ++) {
            if (s[i] == '(') {
                curr ++;
                
            } else if (curr) {
                curr --;
                
                if (!curr) {
                    length = max(length, i - prev);
                }
                
            } else {
                prev = i;
            }
        }
        
        prev = n;
        curr = 0;
        
        for (int i = n - 1; i >= 0; i --) {
            if (s[i] == ')') {
                curr ++;
                
            } else if (curr) {
                curr --;
                
                if (!curr) {
                    length = max(length, prev - i);
                }
                
            } else {
                prev = i;
            }
        }
        
        return length;
    }
};
    