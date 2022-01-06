class Solution{
    public:
    void solve(vector<vector<int>> &m, int n, int i, int j, string curr, vector<string> &ans) {
        if (i < 0 || j < 0 || i >= n || j >= n || m[i][j] == 0) {
            return;
        }
        
        if (i == n - 1 && j == n - 1) {
            ans.push_back(curr);
            return;
        }
        
        m[i][j] = 0;
        
        solve(m, n, i + 1, j, curr + 'D', ans);
        solve(m, n, i, j - 1, curr + 'L', ans);
        solve(m, n, i, j + 1, curr + 'R', ans);
        solve(m, n, i - 1, j, curr + 'U', ans);
        
        m[i][j] = 1;
        return;
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        if (m[0][0] == 0) {
            return {};
        }
        
        solve(m, n, 0, 0, "", ans);
        return ans;
    }
};
