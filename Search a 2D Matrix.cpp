class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int x = 0;
        int y = matrix[0].size() - 1;
        
        while (x >= 0 && y >= 0 && x < matrix.size() && y < matrix[0].size()) {
            if (matrix[x][y] == target) {
                return true;
            } else if (matrix[x][y] > target) {
                y --;
            } else {
                x ++;
            }
        }
        
        return false;
    }
};
