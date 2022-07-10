class Solution {
private:
    int right, left, down, up;
    vector<int> x, y;
    
public:
    Solution() {
        x = {-1, 1, 0, 0};
        y = {0, 0, -1, 1};
        right = 1;
        left = 2;
        down = 3;
        up = 4;
    }
    
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int> (m, 1e9));
        queue<vector<int>> q;
        q.push({0, 0});
        dp[0][0] = 0;
        while (!q.empty()) {
            int r = q.front()[0];
            int c = q.front()[1];
            q.pop();
            for (int i = 0; i < 4; i ++) {
                int row = r + x[i];
                int col = c + y[i];
                if (row < 0 || col < 0 || row == n || col == m) {
                    continue; 
                }
                int newD = dp[r][c];
                if (col > c && grid[r][c] != right) newD ++;
                if (row > r && grid[r][c] != down) newD ++;
                if (col < c && grid[r][c] != left) newD ++;
                if (row < r && grid[r][c] != up) newD ++;
                if (dp[row][col] > newD) {
                    dp[row][col] = newD;
                    q.push({row, col});
                }
            }
        }
        // for (auto i: dp) {
        //     for (auto j: i) {
        //         cout << j << " ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;
        return dp[n - 1][m - 1];
    }
};