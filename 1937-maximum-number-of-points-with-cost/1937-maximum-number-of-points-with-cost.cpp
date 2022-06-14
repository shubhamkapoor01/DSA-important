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
            
            pref[0] = prev[0];
            suff[m - 1] = prev[m - 1];
            
            for (int j = 1; j < m; j ++) {
                pref[j] = max(pref[j - 1] - 1LL, prev[j]);
            }
            
            for (int j = m - 2; j >= 0; j --) {
                suff[j] = max(suff[j + 1] - 1LL, prev[j]);
            }
            
            for (int j = 0; j < m; j ++) {
                curr[j] = points[i][j] + max(pref[j], suff[j]);
                prev[j] = curr[j];
            }
        }
        
        return *max_element(prev.begin(), prev.end());
    }
};