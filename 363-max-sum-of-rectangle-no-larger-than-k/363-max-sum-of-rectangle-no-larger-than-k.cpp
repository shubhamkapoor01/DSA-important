class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& v, int k) {
        int n = v.size();
        int m = v[0].size();
        
        for (int i = 0; i < n; i ++) {
            for (int j = 1; j < m; j ++) {
                v[i][j] += v[i][j - 1];
            }
        }
        
        int ans = INT_MIN;
        
        for (int l = 0; l < m; l ++) {
            for (int r = l; r < m; r ++) {
                set<int> st = {0};
                int prefix = 0;
                
                for (int i = 0; i < n; i ++) {
                    prefix += v[i][r] - (l > 0 ? v[i][l - 1] : 0);
                    
                    auto it = st.lower_bound(prefix - k);
                    
                    if (it != st.end()) {
                        ans = max(ans, prefix - *it);
                    }
                    
                    st.insert(prefix);
                }
            }
        }
        
        return ans == INT_MIN ? -1 : ans;
    }
};

