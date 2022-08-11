class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& v) {
        int m = v[0].size();
        int n = v.size();
        
        vector<vector<int>> dist(n, vector<int> (m, 1e9));
        dist[0][0] = 0;
        
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, 0, 0});
        
        vector<int> x = {-1, 1, 0, 0};
        vector<int> y = {0, 0, -1, 1};
        
        while (pq.size()) {
            int d = pq.top()[0];
            int r = pq.top()[1];
            int c = pq.top()[2];
            
            if (r == n - 1 && c == m - 1) {
                return d;
            }
            
            pq.pop();
            
            for (int i = 0; i < 4; i ++) {
                int row = r + x[i];
                int col = c + y[i];
                
                if (row < 0 || col < 0 || row >= n || col >= m) {
                    continue;
                }
                
                if (max(abs(v[row][col] - v[r][c]), d) < dist[row][col]) {
                    dist[row][col] = max(abs(v[row][col] - v[r][c]), d);
                    pq.push({dist[row][col], row, col});
                }
            }
        }
        
        return 1e9;
    }
};