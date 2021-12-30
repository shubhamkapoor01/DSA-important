class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int rowl = 0;
        int rowr = n - 1;
        
        while (rowl <= rowr) {
            int rowm = (rowl + rowr) / 2;
            if (target <= matrix[rowm][m - 1] && target >= matrix[rowm][0]) {
                int l = 0;
                int r = m - 1;
                
                while (l <= r) {
                    int mid = (l + r) / 2;
                    
                    if (matrix[rowm][mid] == target) {
                        return true;
                    } else if (target > matrix[rowm][mid]) {
                        l = mid + 1;
                    } else {
                        r = mid - 1;
                    }
                }
                return false;
                
            } else if (target > matrix[rowm][m - 1]) {
                rowl = rowm + 1;
            } else {
                rowr = rowm - 1;
            }
        }
        
        return false;
    }
};
