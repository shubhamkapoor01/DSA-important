vector<int> Solution::prevSmaller(vector<int> &arr) {
    int n = arr.size();
    stack<int> st;
    st.push(arr[0]);
    vector<int> ans(n, -1);
    
    for (int i = 1; i < n; i ++) {
        while (!st.empty() && st.top() >= arr[i]) {
            st.pop();
        }
        
        if (st.empty()) {
            ans[i] = -1;
        } else {
            ans[i] = st.top();
        }
        
        st.push(arr[i]);
    }
    return ans;
}
