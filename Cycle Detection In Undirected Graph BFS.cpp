string cycleDetection (vector<vector<int>>& edges, int n, int m) {
    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < m; i ++) {
        graph[edges[i][0]].push_back(edges[i][1]);
        graph[edges[i][1]].push_back(edges[i][0]);
    }
    vector<bool> vis(n + 1, false);
    queue<pair<int, int>> q;
    for (int i = 1; i <= n; i ++) {
        if (!vis[i]) {
            q.push({i, -1});
            vis[i] = true;
            while (!q.empty()) {
                int curr = q.front().first;
                int par = q.front().second;
                q.pop();
                
                for (auto i: graph[curr]) {
                    if (vis[i] && par != i) {
                        return "Yes";
                    }
                    if (!vis[i]) {
                        q.push({i, curr});
                        vis[i] = true;
                    }
                }
            }
        }
    }
    return "No";
}
