class Solution {
public:
    string minRemoveToMakeValid(string s) {
        set<int> extraOpen;
        set<int> extraClose;
        
        for (int i = 0; i < s.size(); i ++) {
            if (s[i] == '(') {
                extraOpen.insert(i);
                
            } else if (s[i] == ')') {
                if (!extraOpen.size()) {
                    extraClose.insert(i);
                    
                } else {
                    extraOpen.erase(prev(extraOpen.end()));
                }
            }
        }
        
        string ans;
        for (int i = 0; i < s.size(); i ++) {
            if (extraOpen.find(i) != extraOpen.end() || extraClose.find(i) != extraClose.end()) {
                continue;
            }
            ans.push_back(s[i]);
        }
        
        return ans;
    }
};