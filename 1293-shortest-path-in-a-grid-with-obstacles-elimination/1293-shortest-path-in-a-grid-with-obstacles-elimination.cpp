class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = -1;
        
        queue<vector<int>> q;
        q.push({0, 0, 0, k});
        
        unordered_set<string> s;
        string key = "0 0 " + to_string(k);
        s.insert(key);
        
        while (!q.empty()) {
            int i = q.front()[0];
            int j = q.front()[1];
            int turn = q.front()[2];
            int rem = q.front()[3];
            q.pop();
            
            if (!rem && grid[i][j]) {
                continue;
            }
            
            if (i == n - 1 && j == m - 1) {
                ans = turn;
                break;
            }
            
            if (grid[i][j]) {
                rem --;
            }
            
            string key = to_string(i - 1) + " " + to_string(j) + " " + to_string(rem);
            if (i > 0 && s.find(key) == s.end()) {
                q.push({i - 1, j, turn + 1, rem});
                s.insert(key);
            }
            
            key = to_string(i) + " " + to_string(j - 1) + " " + to_string(rem);
            if (j > 0 && s.find(key) == s.end()) {
                q.push({i, j - 1, turn + 1, rem});
                s.insert(key);
            }
            
            key = to_string(i + 1) + " " + to_string(j) + " " + to_string(rem);
            if (i < n - 1 && s.find(key) == s.end()) {
                q.push({i + 1, j, turn + 1, rem});
                s.insert(key);
            }
            
            key = to_string(i) + " " + to_string(j + 1) + " " + to_string(rem);
            if (j < m - 1 && s.find(key) == s.end()) {
                q.push({i, j + 1, turn + 1, rem});
                s.insert(key);
            }
        }
        
        return ans;
    }
};