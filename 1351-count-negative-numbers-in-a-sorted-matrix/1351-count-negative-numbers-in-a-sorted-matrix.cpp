class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int j = grid[0].size() - 1;
        int cnt = 0;
        int i = 0;
        
        while (i < grid.size() && j >= 0) {
            while (j >= 0 && grid[i][j] < 0) {
                j --;
            }
            cnt += grid[0].size() - (j + 1);
            i ++;
        }
        
        cnt += i < grid.size() ? (grid.size() - i) * (grid[0].size() - (j + 1)) : 0;
        return cnt;
    }
};