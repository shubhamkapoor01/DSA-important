bool cycle(vector<vector<int>>& graph, vector<bool>& vis, int curr, int par) {
    vis[curr] = true;
    for (auto i: graph[curr]) {
        if (vis[i] && par != i) {
            return true;
        }
        if (!vis[i] && cycle(graph, vis, i, curr)) {
   			return true;
        }
    }
    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m) {
    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < m; i ++) {
        graph[edges[i][0]].push_back(edges[i][1]);
        graph[edges[i][1]].push_back(edges[i][0]);
    }
    vector<bool> vis(n + 1, false);
    for (int i = 1; i <= n; i ++) {
        if (!vis[i] && cycle(graph, vis, i, -1)) {
            return "Yes";
        }
    }
    return "No";
}
