class Solution {
private:
    int n, m;
    
public:
    int maximalRectangleInHistogram(vector<int>& v) {
        vector<int> nextSmaller(m, m);
        vector<int> prevSmaller(m, -1);
        
        stack<int> st;
        st.push(m - 1);
        
        for (int i = m - 2; i >= 0; i --) {
            while (!st.empty() && v[i] <= v[st.top()]) {
                st.pop();
            }
            
            if (st.empty()) {
                nextSmaller[i] = m;
                st.push(i);
                
            } else {
                nextSmaller[i] = st.top();
                st.push(i);
            }
        }
        
        while (!st.empty()) {
            st.pop();
        }
        st.push(0);
        
        for (int i = 1; i < m; i ++) {
            while (!st.empty() && v[i] <= v[st.top()]) {
                st.pop();
            }
            
            if (st.empty()) {
                prevSmaller[i] = -1;
                st.push(i);
                
            } else {
                prevSmaller[i] = st.top();
                st.push(i);
            }
        }
        
        int ans = 0;
        for (int i = 0; i < m; i ++) {
            ans = max(ans, v[i] * (nextSmaller[i] - prevSmaller[i] - 1));
        }
        
        return ans;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();
        
        vector<int> v(m, 0);
        int answer = INT_MIN;
        
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < m; j ++) {
                if (matrix[i][j] == '1') {
                    v[j] += 1;
                } else {
                    v[j] = 0;
                }
            }
            answer = max(answer, maximalRectangleInHistogram(v));
        }
        
        return answer;
    }
};