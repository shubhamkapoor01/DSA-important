class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<int> v(n2, -1);
        vector<int> ans(n1);
        
        stack<int> st;
        st.push(nums2[n2 - 1]);
        int curr = nums2[n2 - 1];
        
        for (int i = n2 - 2; i >= 0; i --) {
            while (!st.empty() && st.top() < nums2[i]) {
                st.pop();
            }
            
            if (!st.empty()) {
                v[i] = st.top();
            }
            
            st.push(nums2[i]);
        }
        
        unordered_map<int, int> m;
        for (int i = 0; i < n2; i ++) {
            m[nums2[i]] = i;
        }
        
        for (int i = 0; i < n1; i ++) {
            ans[i] = v[m[nums1[i]]];
        }
        
        return ans;
    }
};
