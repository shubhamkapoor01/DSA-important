class Solution {
public:
    vector<int> getNextSmaller(vector<int> arr) {
        int n = arr.size();
        vector<int> ans(n, -1);
        stack<int> st;
        st.push(n - 1);
        
        for (int i = n - 2; i >= 0; i --) {
            while (!st.empty() && arr[i] <= arr[st.top()]) {
                st.pop();
            }
            
            if (st.empty()) {
                ans[i] = -1;
            } else {
                ans[i] = st.top();
            }
            
            st.push(i);
        }
        
        return ans;
    }
    
    vector<int> getPrevSmaller(vector<int> arr) {
        int n = arr.size();
        vector<int> ans(n, -1);
        stack<int> st;
        st.push(0);
        
        for (int i = 1; i < n; i ++) {
            while (!st.empty() && arr[i] <= arr[st.top()]) {
                st.pop();
            }
            
            if (st.empty()) {
                ans[i] = -1;
            } else {
                ans[i] = st.top();
            }
            
            st.push(i);
        }
        
        return ans;
    }
    
    int largestRectangleArea(vector<int>& heights) {
        vector<int> nextSmaller = getNextSmaller(heights);
        vector<int> prevSmaller = getPrevSmaller(heights);
        
        int maxArea = 0;
        int n = heights.size();
        for (int i = 0; i < n; i ++) {
            if (nextSmaller[i] == -1) {
                nextSmaller[i] = n;
            }
            
            maxArea = max(maxArea, heights[i] * (nextSmaller[i] - prevSmaller[i] - 1));
        }
        
        return maxArea;
    }
};
