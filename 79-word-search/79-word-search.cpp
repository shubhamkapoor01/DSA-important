class Solution {
private:
    bool dfs(vector<vector<char>>& board, int i, int j, int idx, string word) {
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size()) {
            return false;
        }
        
        if (idx == word.size() - 1 && board[i][j] == word[idx]) {
            return true;
        }
        
        if (board[i][j] != word[idx]) {
            return false;
        }
        
        bool ans = false;
        char v = board[i][j];
        board[i][j] = '#';
        
        ans |= dfs(board, i + 1, j, idx + 1, word);
        ans |= dfs(board, i - 1, j, idx + 1, word);
        ans |= dfs(board, i, j + 1, idx + 1, word);
        ans |= dfs(board, i, j - 1, idx + 1, word);
        
        board[i][j] = v;
        return ans;
    }
    
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < m; j ++) {
                if (board[i][j] == word[0] && dfs(board, i, j, 0, word)) {
                    return true;
                }
            }
        }
        return false;
    }
};