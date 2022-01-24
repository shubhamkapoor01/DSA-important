class Solution {
public:
    void dfs(vector<vector<int>> &v, int i, int j, int x, int old, vector<vector<bool>> &vis) {
        int n = v.size();
        int m = v[0].size();
        
        if (i >= n || j >= m || i < 0 || j < 0 || v[i][j] != old || vis[i][j]) {
            return;
        }
        
        v[i][j] = x;
        vis[i][j] = true;
        
        dfs(v, i + 1, j, x, old, vis);
        dfs(v, i - 1, j, x, old, vis);
        dfs(v, i, j + 1, x, old, vis);
        dfs(v, i, j - 1, x, old, vis);
        return;
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        vector<vector<bool>> vis(image.size(), vector<bool> (image[0].size(), false));
        dfs(image, sr, sc, newColor, image[sr][sc], vis);
        return image;
    }
};
