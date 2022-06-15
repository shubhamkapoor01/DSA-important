class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        bool ele1 = matrix[0][0];
        bool row1 = 1;
        bool col1 = 1;
        
        for (int i = 0; i < m; i ++) {
            if (!matrix[0][i]) {
                row1 = 0;
            }
        }
        
        for (int i = 0; i < n; i ++) {
            if (!matrix[i][0]) {
                col1 = 0;
            }
        }
        
        for (int i = 1; i < n; i ++) {
            for (int j = 1; j < m; j ++) {
                if (!matrix[i][j]) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        for (int i = 1; i < n; i ++) {
            if (!matrix[i][0]) {
                for (int j = 1; j < m; j ++) {
                    matrix[i][j] = 0;
                }
            }
        }
        
        for (int j = 1; j < m; j ++) {
            if (!matrix[0][j]) {
                for (int i = 1; i < n; i ++) {
                    matrix[i][j] = 0;
                }
            }
        }
        
        if (!ele1) {
            for (int i = 0; i < m; i ++) {
                matrix[0][i] = 0;
            }
            for (int i = 0; i < n; i ++) {
                matrix[i][0] = 0;
            }    
        }
        
        if (ele1 && !col1) {
            for (int i = 0; i < n; i ++) {
                matrix[i][0] = 0;
            }   
        }
        
        if (ele1 && !row1) {
            for (int i = 0; i < m; i ++) {
                matrix[0][i] = 0;
            }
        }
        
        return;
    }
};