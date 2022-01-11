class Solution {
    public:
    int celebrity(vector<vector<int>>& M, int n) {
        stack<int> st;
        for (int i = 0; i < n; i ++) {
            st.push(i);
        }
        
        while (st.size() > 1) {
            int c1 = st.top();
            st.pop();
            int c2 = st.top();
            st.pop();
            
            if (M[c1][c2] && !M[c2][c1]) {
                st.push(c2);
            } else if (M[c2][c1] && !M[c1][c2]) {
                st.push(c1);
            }
        }
        
        int candidate = st.top();
        int confirm = true;
        
        for (int i = 0; i < n; i ++) {
            if (i == candidate) {
                continue;
            }
            
            if (!M[i][candidate]) {
                confirm = false;
                break;
            }
        }
        
        for (int j = 0; j < n; j ++) {
            if (j == candidate) {
                continue;
            }
            
            if (M[candidate][j]) {
                confirm = false;
                break;
            }
        }
        
        if (confirm) {
            return candidate;
        } else {
            return -1;
        }
    }
};
