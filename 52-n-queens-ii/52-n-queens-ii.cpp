class Solution {
public:
    void solve(int n, int row, int& ans, 
                vector<bool>& vr, vector<bool>& vc, 
                  vector<bool>& ld, vector<bool>& rd) {
        
        if (row == n) {
            ans ++;
            return;
        }
        
        for (int i = 0; i < n; i ++) {
            if (!vr[row] && !vc[i] && !ld[n - 1 + i - row] && !rd[row + i]) {
                ld[n - 1 + i - row] = true;
                rd[row + i] = true;
                vr[row] = true;
                vc[i] = true;
                
                solve(n, row + 1, ans, vr, vc, ld, rd);
                
                vc[i] = false;
                vr[row] = false;
                rd[row + i] = false;
                ld[n - 1 + i - row] = false;
            }
        }
    }
    
    int totalNQueens(int n) {
        vector<bool> vr(n, false);
        vector<bool> vc(n, false);
        vector<bool> ld(2 * n, false);
        vector<bool> rd(2 * n, false);
        
        int ans = 0;
        solve(n, 0, ans, vr, vc, ld, rd);
        return ans;
    }
};