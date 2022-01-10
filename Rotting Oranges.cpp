class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool> (m, false));
        
        queue<pair<int, pair<int, int>>> q;
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < m; j ++) {
                if (grid[i][j] == 2) {
                    q.push({0, {i, j}});
                }
            }
        }
    
        int time = 0;
        
        while (!q.empty()) {
            int x = q.front().second.first;
            int y = q.front().second.second;
            int t = q.front().first;
            vis[x][y] = true;
            time = t;
            q.pop();
            
            if (x > 0 && !vis[x - 1][y] && grid[x - 1][y] == 1) {
                q.push({t + 1, {x - 1, y}});
                grid[x - 1][y] = 2;
            }
            
            if (y > 0 && !vis[x][y - 1] && grid[x][y - 1] == 1) {
                q.push({t + 1, {x, y - 1}});
                grid[x][y - 1] = 2;
            }
            
            if (x < n - 1 && !vis[x + 1][y] && grid[x + 1][y] == 1) {
                q.push({t + 1, {x + 1, y}});
                grid[x + 1][y] = 2;
            }
            
            if (y < m - 1 && !vis[x][y + 1] && grid[x][y + 1] == 1) {
                q.push({t + 1, {x, y + 1}});
                grid[x][y + 1] = 2;
            }
        }
        
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < m; j ++) {
                if (grid[i][j] == 1) {
                    return -1;
                }
            }
        }
        
        return time;
    }
};
