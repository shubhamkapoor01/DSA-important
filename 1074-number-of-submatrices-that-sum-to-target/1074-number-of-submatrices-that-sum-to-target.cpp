class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& v, int t) {
        int n = v.size();
        int m = v[0].size();
        for (int i = 0; i < n; i ++) {
            for (int j = 1; j < m; j ++) {
                v[i][j] += v[i][j - 1];
            }
        }
        int count = 0;
        for (int c1 = 0; c1 < m; c1 ++) {
            for (int c2 = 0; c2 <= c1; c2 ++) {
                unordered_map<int, int> mp;
                mp[0] = 1;
                
                int prefix = 0;
                for (int i = 0; i < n; i ++) {
                    prefix += v[i][c1] - (c2 > 0 ? v[i][c2 - 1] : 0);
                    if (mp.find(prefix - t) != mp.end()) {
                        count += mp[prefix - t];
                    }
                    mp[prefix] ++;
                }
            }
        }
        return count;
    }
};