class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> value;
        
        value['I'] = 1;
        value['V'] = 5;
        value['X'] = 10;
        value['L'] = 50;
        value['C'] = 100;
        value['D'] = 500;
        value['M'] = 1000;
        
        int ans = 0;
        int n = s.size();
        
        if (n == 1) {
            return value[s[0]];
        }
        
        for (int i = 0; i < n - 1; i ++) {
            if (value[s[i]] < value[s[i + 1]]) {
                ans += value[s[i + 1]] - value[s[i]];
                i ++;
                
                if (i == n - 2) {
                    ans += value[s[i + 1]];
                }
                
            } else {
                ans += value[s[i]];
                
                if (i == n - 2) {
                    ans += value[s[i + 1]];
                }
            }
        }
        
        return ans;
    }
};