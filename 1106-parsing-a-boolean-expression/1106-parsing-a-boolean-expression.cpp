class Solution {
public:
    bool parseBoolExpr(string& exp) {
        stack<char> s;
        for (auto ch : exp) {
            if (ch == ')') {
                bool hasT = false;
                bool hasF = false;
                while (s.top() == 't' || s.top() == 'f') {
                    hasT |= s.top() == 't';
                    hasF |= s.top() == 'f';
                    s.pop();
                }
                char op = s.top();
                s.pop();
                if (op == '!') s.push(hasT ? 'f' : 't');
                if (op == '&') s.push(hasF ? 'f' : 't');
                if (op == '|') s.push(hasT ? 't' : 'f');
            
            } else if (ch != ',' && ch != '(') {
                s.push(ch);
            }
        }
        return s.top() == 't';
    }
};