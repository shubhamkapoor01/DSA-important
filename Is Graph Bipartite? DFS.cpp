class Solution {
public:
    int bipartite(vector<vector<int>>& graph, int curr, int col, vector<bool>& vis, vector<int>& color) {
        if (vis[curr]) {
            if(col == color[curr]) {
                return true;
            } else {
                return false;
            }
        }
        
        vis[curr] = true;
        color[curr] = col;
        
        for (auto i: graph[curr]) {
            if (!bipartite(graph, i, 1 - col, vis, color)) {
                return false;
            }
        }
        
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        vector<bool> vis(n, false);
        for (int i = 0; i < n; i ++) {
            if (!vis[i] && !bipartite(graph, i, 0, vis, color)) {
                return false;
            }
        }
        return true;
    }
};
