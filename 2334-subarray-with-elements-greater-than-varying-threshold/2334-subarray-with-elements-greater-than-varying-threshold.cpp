#define ll long long

class Solution {
private:
    void fillNextSmaller(vector<int>& nextSmaller, vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        st.push(n - 1);
        
        nextSmaller[n - 1] = n;
        for (int i = n - 2; i >= 0; i --) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            
            if (st.empty()) {
                nextSmaller[i] = n;
            } else {
                nextSmaller[i] = st.top();
            }
            
            st.push(i);
        }
    }
    
    void fillPrevSmaller(vector<int>& prevSmaller, vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        st.push(0);
        
        prevSmaller[0] = -1;
        for (int i = 1; i < n; i ++) {
            while (!st.empty()  && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            
            if (st.empty()) {
                prevSmaller[i] = -1;
            } else {
                prevSmaller[i] = st.top();
            }
            
            st.push(i);
        }
    }
    
public:
    int validSubarraySize(vector<int>& nums, int threshold) {
        int n = nums.size();
        
        vector<int> nextsmaller(n);
        vector<int> prevsmaller(n);
        
        fillNextSmaller(nextsmaller, nums);
        fillPrevSmaller(prevsmaller, nums);
        
        for (int i = 0; i < n; i ++) {
            int len = nextsmaller[i] - prevsmaller[i] - 1;
            if (nums[i] > threshold / len) {
                return len;
            }
        }
        
        return -1;
    }
};