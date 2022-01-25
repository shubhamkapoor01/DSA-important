class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        vector<bool> vis(n, false);
        
        for (int i = 0; i < n; i ++) {
            if (!vis[i]) {
                int col = 0;
                color[i] = 0;
                
                vis[i] = true;
                queue<int> q;
                q.push(i);
                
                while (!q.empty()) {
                    int front = q.front();
                    col = 1 - color[front];
                    q.pop();
                    
                    for (auto it: graph[front]) {
                        if (color[it] == -1) {
                            color[it] = col;
                        }
                        
                        if (vis[it]) {
                            if (color[it] != col) {
                                return false;
                            }
                            continue;
                        }
                        
                        vis[it] = true;
                        q.push(it);
                    }
                }
            }
        }
        return true;
    }
};
