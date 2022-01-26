class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<double, int>>> graph(n);
        for (int i = 0; i < edges.size(); i ++) {
            graph[edges[i][0]].push_back({succProb[i], edges[i][1]});
            graph[edges[i][1]].push_back({succProb[i], edges[i][0]});
        }
        
        vector<double> probNode(n, 0);
        priority_queue<pair<double, int>> pq;
        
        pq.push({1.0, start});
        probNode[start] = 1;
        
        while (!pq.empty()) {
            int idx = pq.top().second;
            double prob = pq.top().first;
            pq.pop();
            
            for (auto i: graph[idx]) {
                if (prob * i.first > probNode[i.second]) {
                    probNode[i.second] = prob* i.first;
                    pq.push({probNode[i.second], i.second});
                }
            }
        }
        
        return probNode[end];
    }
};
