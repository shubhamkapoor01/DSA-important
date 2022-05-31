class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if (s.size() < k) {
            return false;
        }
        
        unordered_set<int> st;
        int num = 0;
        int ws = 0;
        int we = 0;
        
        while (we < k) {
            if (s[we] == '1') {
                num = 2 * num + 1;
            } else {
                num = 2 * num;
            }
            we ++;
        }
        
        st.insert(num);
        while (we < s.size()) {
            if (s[we] == '1') {
                num = 2 * num + 1;
            } else {
                num = 2 * num;
            }
            
            if (we - ws + 1 > k) {
                if (s[ws] == '1') {
                    num -= (1 << k);
                }
                ws ++;
            }
            
            st.insert(num);
            we ++;
        }
        
        bool present = true;
        
        for (int x = 0; x < (1 << k); x ++) {
            if (st.find(x) == st.end()) {
                present = false;
                break;
            }
        }
            
        return present;
    }
};