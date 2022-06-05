class Solution {
public:
    static bool compare(vector<int>& x, vector<int>& y) {
        if (x[0] < y[0]) return true;
        if (x[0] > y[0]) return false;
        return x[1] > y[1];
    }
        
    vector<int> nextGreaterElements(vector<vector<int>>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);
        
        stack<int> st;
        st.push(n - 1);
        
        for (int i = n - 1; i >= 0; i --) {
            while (!st.empty() && nums[st.top()][1] <= nums[i][1]) {
                st.pop();
            }
            
            if (!st.empty()) {
                ans[i] = st.top();
            }
            
            st.push(i);
        }
        
        return ans;
    }
    
    int numberOfWeakCharacters(vector<vector<int>>& v) {
        sort(v.begin(), v.end(), compare);
        int n = v.size();
        vector<int> ans = nextGreaterElements(v);
        int cnt = 0;
        for (int i = 0; i < n; i ++) {
            if (ans[i] != -1) {
                cnt ++;
            }
        }
        return cnt;
    }
};