class Solution {
public:
    void solve(int n, int row, vector<string> board, vector<vector<string>>& ans, 
               vector<bool> vr, vector<bool> vc, vector<bool> ld, vector<bool> rd) {
        
        if (row == n) {
            ans.push_back(board);
            return;
        }
        
        for (int i = 0; i < n; i ++) {
            if (!vr[row] && !vc[i] && !ld[n - 1 + i - row] && !rd[row + i]) {
                board[row][i] = 'Q';
                ld[n - 1 + i - row] = true;
                rd[row + i] = true;
                vr[row] = true;
                vc[i] = true;
                
                solve(n, row + 1, board, ans, vr, vc, ld, rd);
                
                vc[i] = false;
                vr[row] = false;
                rd[row + i] = false;
                ld[n - 1 + i - row] = false;
                board[row][i] = '.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < n; j ++) {
                board[i].push_back('.');
            }
        }
        
        vector<bool> vr(n, false);
        vector<bool> vc(n, false);
        vector<bool> ld(2 * n, false);
        vector<bool> rd(2 * n, false);
        solve(n, 0, board, ans, vr, vc, ld, rd);
        return ans;
    }
};
