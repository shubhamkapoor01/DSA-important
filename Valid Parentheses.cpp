class Solution {
public:
    bool isValid(string s) {
        if (s[0] == ')' || s[0] == ']' || s[0] == '}') {
            return false;
        }
        
        stack<char> st;
        st.push(s[0]);
        int n = s.size();
    
        for (int i = 1; i < n; i ++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                st.push(s[i]);
                continue;
            }
            
            if (!st.empty()) {
                if (s[i] == ')' && st.top() != '(') {
                    return false;
                } else if (s[i] == ')') {
                    st.pop();
                }
                
                if (s[i] == ']' && st.top() != '[') {
                    return false;
                } else if (s[i] == ']') {
                    st.pop();
                }
                
                if (s[i] == '}' && st.top() != '{') {
                    return false;
                } else if (s[i] == '}') {
                    st.pop();
                }
                
            } else {
                return false;
            }
        }
        
        return st.empty();
    }
};
