class Solution{
	public:
    vector<int> bellman_ford(int V, vector<vector<int>> adj, int S) {
        vector<vector<pair<int, int>>> graph(V);
        for (int i = 0; i < adj.size(); i ++) {
            graph[adj[i][0]].push_back({adj[i][1], adj[i][2]});
        }
        
        vector<int> dist(V, 1e8);
        dist[S] = 0;
        
        for (int i = 0; i < V - 1; i ++) {
            for (int j = 0; j < graph.size(); j ++) {
                for (int k = 0; k < graph[j].size(); k ++) {
                    dist[graph[j][k].first] = min(dist[graph[j][k].first], dist[j] + graph[j][k].second);
                }
            }
        }
        
        return dist;
    }
};
