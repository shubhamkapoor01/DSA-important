class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> m;
        int ws = 0;
        int we = 0;
        int ans = 0;
    
        while (we < s.size()) {
            m[s[we]] ++;
            
            while (m[s[we]] > 1) {
                m[s[ws]] --;
                ws ++;
            }
            
            ans = max(ans, we - ws + 1);
            we ++;
        }
        
        return ans;
    }
};
