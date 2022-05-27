class Solution {
public:
    string minRemoveToMakeValid(string s) {
        vector<int> extraOpen;
        vector<int> extraClose;
        
        for (int i = 0; i < s.size(); i ++) {
            if (s[i] == '(') {
                extraOpen.push_back(i);
                
            } else if (s[i] == ')') {
                if (!extraOpen.size()) {
                    extraClose.push_back(i);
                    
                } else {
                    extraOpen.pop_back();
                }
            }
        }
        
        string ans;
        int i = 0;
        int j = 0;
        
        for (int idx = 0; idx < s.size(); idx ++) {
            if (i < extraOpen.size() && extraOpen[i] == idx) {
                i ++;
                continue;
            }
            
            if (j < extraClose.size() && extraClose[j] == idx) {
                j ++;
                continue;
            }
            ans.push_back(s[idx]);
        }
        
        return ans;
    }
};