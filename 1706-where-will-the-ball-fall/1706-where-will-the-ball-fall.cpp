class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> v(m);
        for (int i = 0; i < m; i ++) {
            bool can = true;
            int idx = i;
            for (int j = 0; j < n; j ++) {
                if (grid[j][idx] == 1 && idx < m - 1 && grid[j][idx + 1] == 1) {
                    idx ++;
                } else if (grid[j][idx] == -1 && idx > 0 && grid[j][idx - 1] == -1) {
                    idx --;
                } else {
                    can = false;
                    break;
                }
            }
            if (!can) {
                v[i] = -1;
            } else {
                v[i] = idx;
            }
        }
        return v;
    }
};