class Solution {
public:
    bool possible(vector<vector<char>>& board, int r, int c, int x) {
        
        for(int i = 0; i < 9; i++) {
            if (board[i][c] == x) {
                return false;
            }
        }
        
        for(int i = 0; i < 9; i++) {
            if (board[r][i] == x) {
                return false; 
            }
        }
            
        int br = 3 * (r / 3);
        int bc = 3 * (c / 3);
        
        for (int i = br; i < br + 3; i ++) {
            for (int j = bc; j < bc + 3; j ++) {
                if (board[i][j] == x) {
                    return false;
                }
            }
        }
        
        return true;
    }
    
    bool solve(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i ++) {
            for (int j = 0; j < 9; j ++) {
                if (board[i][j] == '.') {
                    for (char k = '1'; k <= '9'; k ++) {
                        if (possible(board, i, j, k)) {
                            board[i][j] = k;
                            
                            if (solve(board)) {
                                return true;
                            } else {
                                board[i][j] = '.';
                            }
                        }
                    }
                    return false;
                }   
            }
        }
        return true;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};
