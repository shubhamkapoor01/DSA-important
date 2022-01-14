class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        
        vector<int> l1(256, 0);
        vector<int> l2(256, 0);
        
        for (int i = 0; i < s.size(); i ++) {
            l1[s[i] - '0'] ++;
            l2[t[i] - '0'] ++;
        }
        
        for (int i = 0; i < 256; i ++) {
            if (l1[i] != l2[i]) {
                return false;
            }
        }
        
        return true;
    }
};
