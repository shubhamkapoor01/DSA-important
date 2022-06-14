class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int m = points[0].size();
        
        vector<long long> prev(m, 0);
        vector<long long> curr(m, 0);
        
        for (int i = 0; i < m; i ++) {
            prev[i] = points[0][i];
        }
        
        for (int i = 1; i < n; i ++) {
            vector<long long> pref(m, 0);
            vector<long long> suff(m, 0);
            
            for (int j = 0; j < m; j ++) {
                if (j != 0) pref[j] = max(pref[j - 1] - 1LL, prev[j]);
                if (j == 0) pref[j] = prev[j];
            }
            
            for (int j = m - 1; j >= 0; j --) {
                if (j != m - 1) suff[j] = max(suff[j + 1] - 1LL, prev[j]);
                if (j == m - 1) suff[j] = prev[j];
            }
            
            for (int j = 0; j < m; j ++) {
                curr[j] = points[i][j] + max(pref[j], suff[j]);
                prev[j] = curr[j];
            }
        }
        
        return *max_element(prev.begin(), prev.end());
    }
};