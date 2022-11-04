class Solution {
public:
    string reverseVowels(string s) {
        unordered_set<char> st;
        
        st.insert('A');
        st.insert('E');
        st.insert('I');
        st.insert('O');
        st.insert('U');
        st.insert('a');
        st.insert('e');
        st.insert('i');
        st.insert('o');
        st.insert('u');
        
        int n = s.size();
        int r = n - 1;
        int l = 0;
        
        while (l < r) {
            if (st.count(s[l]) && st.count(s[r])) {
                swap(s[l], s[r]);
                l ++;
                r --;
            } else if (st.count(s[l])) {
                r --;
            } else {
                l ++;
            }
        }
        
        return s;
    }
};