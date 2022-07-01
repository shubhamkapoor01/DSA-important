class Solution {
public:
    int mctFromLeafValues(vector<int>& v) {
        int n = v.size();
        vector<int> st;
        st.push_back(1e9);
        int ans = 0;
        
        for (int i = 0; i < n; i ++) {
            while (st.back() <= v[i]) {
                int back = st.back();
                st.pop_back();
                ans += back * min(v[i], st.back());
            }
            
            st.push_back(v[i]);
        }
        
        for (int i = 2; i < st.size(); i ++) {
            ans += st[i] * st[i - 1];
        }
        
        return ans;
    }
};