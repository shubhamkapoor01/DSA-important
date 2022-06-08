class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> graph(n);
        for (auto i: roads) {
            graph[i[0]].push_back({i[1], i[2]});
            graph[i[1]].push_back({i[0], i[2]});
        }
        
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
        pq.push({0, 0});
        
        vector<long long> times(n, LLONG_MAX);
        times[0] = 0;
        
        vector<long long> dp(n, 0);
        dp[0] = 1;
        
        while (pq.size()) {
            long long node = pq.top().second;
            long long time = pq.top().first;
            
            pq.pop();
            
            for (auto &child: graph[node]) {
                if (times[child.first] > time + child.second) {
                    pq.push({time + child.second, child.first});
                    times[child.first] = time + child.second;
                    dp[child.first] = dp[node];
                    
                } else if (times[child.first] == time + child.second) {
                    dp[child.first] = (dp[child.first] + dp[node]) % 1000000007;
                }
            }
        }
        
        return dp[n - 1];
    }
};