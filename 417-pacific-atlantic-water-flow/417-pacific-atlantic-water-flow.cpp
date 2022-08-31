class Solution {
    int n, m;
    
    void dfs(vector<vector<int>>& heights, int i, int j, vector<vector<bool>>& vis, int prev) {
        if (i < 0 || j < 0 || i == n || j == m || vis[i][j] || heights[i][j] < prev) {
            return;
        }
        
        vis[i][j] = true;
        dfs(heights, i + 1, j, vis, heights[i][j]);
        dfs(heights, i - 1, j, vis, heights[i][j]);
        dfs(heights, i, j + 1, vis, heights[i][j]);
        dfs(heights, i, j - 1, vis, heights[i][j]);
        return;
    }
    
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        n = heights.size();
        m = heights[0].size();
        
        vector<vector<bool>> pacific(n, vector<bool> (m, false));
        vector<vector<bool>> atlantic(n, vector<bool> (m, false));
        
        for (int i = 0; i < n; i ++) {
            dfs(heights, i, 0, pacific, -1);
            dfs(heights, i, m - 1, atlantic, -1);
        }
        
        for (int j = 0; j < m; j ++) {
            dfs(heights, 0, j, pacific, -1);
            dfs(heights, n - 1, j, atlantic, -1);
        }
        
        vector<vector<int>> ans;
        
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < m; j ++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }
        
        return ans;
    }
};