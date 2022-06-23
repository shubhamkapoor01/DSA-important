class Solution {
private:
    bool possible(vector<vector<char>>& board, int r, int c, char ch) {
        for (int i = 0; i < 9; i ++) {
            if (board[i][c] == ch) {
                return false;
            }
        }
        
        for (int i = 0; i < 9; i ++) {
            if (board[r][i] == ch) {
                return false;
            }
        }
        
        for (int i = 3 * (r / 3); i < 3 * (r / 3) + 3; i ++) {
            for (int j = 3 * (c / 3); j < 3 * (c / 3) + 3; j ++) {
                if (board[i][j] == ch) {
                    return false;
                }
            }
        }
        
        return true;
    }
    
    bool solve(vector<vector<char>>& board, int n = 9) {
        bool done = true;
        for (int r = 0; r < 9; r ++) {
            for (int c = 0; c < 9; c ++) {
                if (board[r][c] == '.') {
                    done = false;
                    break;
                }
            }
            if (!done) {
                break;
            }
        }
                            
        if (done) {
            return true;
        }
        
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < n; j ++) {
                if (board[i][j] == '.') {
                    for (char k = '1'; k <= '9'; k ++) {
                        if (possible(board, i, j, k)) {
                            board[i][j] = k;
                            if (solve(board)) {
                                return true;
                            }
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        
        return false;
    }
    
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
        return;
    }
};