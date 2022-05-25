class Solution {
public:
    int countSquares(vector<vector<int>>& v) {
        int m = v[0].size();
        int n = v.size();
        int total = 0;
        
        for (int i = 0; i < n; i ++) {
            if (v[i][0]) {
                total ++;
            }
        }
        
        for (int j = 1; j < m; j ++) {
            if (v[0][j]) {
                total ++;
            }
        }
        
        for (int i = 1; i < n; i ++) {
            for (int j = 1; j < m; j ++) {
                if (v[i][j]) {
                    v[i][j] = 1 + min({v[i - 1][j], v[i][j - 1], v[i - 1][j - 1]});
                    total += v[i][j];
                }
            }
        }
        
        return total;
    }
};
    