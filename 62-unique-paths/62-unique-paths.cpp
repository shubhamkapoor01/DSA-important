class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> prev(n, 1);
        vector<int> curr(n, 1);
        
        for (int i = m - 2; i >= 0; i --) {
            for (int j = n - 2; j >= 0; j --) {
                curr[j] = curr[j + 1] + prev[j];
            }
            prev = curr;
        }
        
        return curr[0];
    }
};