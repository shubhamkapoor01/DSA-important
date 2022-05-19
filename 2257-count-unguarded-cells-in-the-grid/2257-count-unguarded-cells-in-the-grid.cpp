struct Directions {
    int u, d, l, r;
};

class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<bool>> w(m, vector<bool> (n, false));
        for (int i = 0; i < walls.size(); i ++) {
            w[walls[i][0]][walls[i][1]] = true;
        }
        
        vector<vector<bool>> g(m, vector<bool> (n, false));
        for (int i = 0; i < guards.size(); i ++) {
            g[guards[i][0]][guards[i][1]] = true;
        }
        
        vector<vector<Directions>> dpw(m, vector<Directions> (n));
        vector<vector<Directions>> dpg(m, vector<Directions> (n));
        
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                dpw[i][j].u = 1e6;
                dpw[i][j].d = 1e6;
                dpw[i][j].l = 1e6;
                dpw[i][j].r = 1e6;
                dpg[i][j].u = 1e8;
                dpg[i][j].d = 1e8;
                dpg[i][j].l = 1e8;
                dpg[i][j].r = 1e8;
            }
        }
        
        for (int i = 0; i < m; i ++) {
            for (int j = 1; j < n; j ++) {
                dpw[i][j].l = w[i][j - 1] ? 1 : 1 + dpw[i][j - 1].l;
                dpg[i][j].l = g[i][j - 1] ? 1 : 1 + dpg[i][j - 1].l;
            }
        }
        
        for (int i = 1; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                dpw[i][j].u = w[i - 1][j] ? 1 : 1 + dpw[i - 1][j].u;
                dpg[i][j].u = g[i - 1][j] ? 1 : 1 + dpg[i - 1][j].u;
            }
        }
        
        for (int i = m - 2; i >= 0; i --) {
            for (int j = 0; j < n; j ++) {
                dpw[i][j].d = w[i + 1][j] ? 1 : 1 + dpw[i + 1][j].d;
                dpg[i][j].d = g[i + 1][j] ? 1 : 1 + dpg[i + 1][j].d;
            }
        }
        
        for (int i = 0; i < m; i ++) {
            for (int j = n - 2; j >= 0; j --) {
                dpw[i][j].r = w[i][j + 1] ? 1 : 1 + dpw[i][j + 1].r;
                dpg[i][j].r = g[i][j + 1] ? 1 : 1 + dpg[i][j + 1].r;
            }
        }
        
        int cnt = 0;
        
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (!g[i][j] && !w[i][j]) {
                    if (dpw[i][j].l < dpg[i][j].l && dpw[i][j].r < dpg[i][j].r && 
                       dpw[i][j].u < dpg[i][j].u && dpw[i][j].d < dpg[i][j].d) {
                        cnt ++;
                    }
                }
            }
        }
        
        return cnt;
    }
};