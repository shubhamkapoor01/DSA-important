class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& graph) {
        int n = graph.size();
        int m = graph[0].size();
        
        vector<vector<bool>> vis(n, vector<bool> (m, false));
        int maxArea = 0;
        
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < m; j ++) {
                if (!vis[i][j] && graph[i][j]) {
                    vis[i][j] = true;
                    int currArea = 1;
                    
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    
                    while (!q.empty()) {
                        int x = q.front().first;
                        int y = q.front().second;
                        q.pop();
                        
                        if (x - 1 >= 0 && !vis[x - 1][y] && graph[x - 1][y]) {
                            q.push({x - 1, y});
                            vis[x - 1][y] = true;
                            currArea ++;
                        }
                        
                        if (x + 1 < n && !vis[x + 1][y] && graph[x + 1][y]) {
                            q.push({x + 1, y});
                            vis[x + 1][y] = true;
                            currArea ++;
                        }
                        
                        if (y - 1 >= 0 && !vis[x][y - 1] && graph[x][y - 1]) {
                            q.push({x, y - 1});
                            vis[x][y - 1] = true;
                            currArea ++;
                        }
                        
                        if (y + 1 < m && !vis[x][y + 1] && graph[x][y + 1]) {
                            q.push({x, y + 1});
                            vis[x][y + 1] = true;
                            currArea ++;
                        }
                    }
                    maxArea = max(maxArea, currArea);
                }
            }
        }
        
        return maxArea;
    }
};