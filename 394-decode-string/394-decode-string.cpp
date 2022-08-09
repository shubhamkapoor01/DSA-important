class Solution {
public:
    string decodeString(string s) {
        if (!s.size()) {
            return "";
        }
        
        int n = s.size();
        int num = 0;
        string ans;
        
        for (int i = 0; i < n; i ++) {
            if (s[i] - '0' >= 0 && s[i] - '0' <= 9) {
                num = num * 10 + (s[i] - '0');
            
            } else if (isalpha(s[i])) {
                ans.push_back(s[i]);
                
            } else {
                int cnt = 1;
                int j = i + 1;
                
                while (j < n && cnt) {
                    if (s[j] == '[') cnt ++;
                    if (s[j] == ']') cnt --;
                    j ++;
                }
                
                string temp = decodeString(s.substr(i + 1, j - i - 2));
                
                while (num) {
                    ans += temp;
                    num --;
                }
                
                i = j - 1;
            }
        }
        
        return ans;
    }
};