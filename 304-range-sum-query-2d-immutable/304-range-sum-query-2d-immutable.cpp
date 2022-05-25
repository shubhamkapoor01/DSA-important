class NumMatrix {
    vector<vector<int>> dp;
    
public:
    NumMatrix(vector<vector<int>>& matrix) {
        dp = matrix;
        
        for (int i = 1; i < matrix.size(); i ++) {
            dp[i][0] += dp[i - 1][0];
        }
        
        for (int i = 1; i < matrix[0].size(); i ++) {
            dp[0][i] += dp[0][i - 1];
        }
        
        for (int i = 1; i < matrix.size(); i ++) {
            for (int j = 1; j < matrix[0].size(); j ++) {
                dp[i][j] += dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return dp[row2][col2] - (row1 > 0 ? dp[row1 - 1][col2] : 0) - (col1 > 0 ? dp[row2][col1 - 1] : 0) + 
                                    ((row1 > 0 && col1 > 0) ? dp[row1 - 1][col1 - 1] : 0);
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */