class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();
        vector<int> ans(n, 0);
        stack<int> st;
        st.push(n - 1);
    
        for (int i = n - 2; i >= 0; i --) {
            int see = 0;
            int mx = 0;
            
            while (!st.empty() && heights[st.top()] < heights[i]) {
                if (heights[st.top()] > mx) {
                    mx = heights[st.top()];
                    see ++;
                }
                
                st.pop();
            }
            
            if (!st.empty()) {
                ans[i] = see + 1;
            } else {
                ans[i] = see;
            }
            
            st.push(i);
        }
        
        return ans;
    }
};