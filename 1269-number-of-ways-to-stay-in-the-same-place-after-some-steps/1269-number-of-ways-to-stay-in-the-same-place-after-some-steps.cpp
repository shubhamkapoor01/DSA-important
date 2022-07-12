class Solution {
public:
    int numWays(int steps, int size) {
        size = min(steps, size);
        int mod = 1000000007;
        
        int prev[size + 1];
        int curr[size + 1];
        
        memset(prev, 0, sizeof(prev));
        memset(curr, 0, sizeof(curr));
        prev[0] = 1;
        
        for (int i = 1; i <= steps; i ++) {
            for (int j = 0; j <= size; j ++) {
                int stay = prev[j];
                int left = j > 0 ? prev[j - 1] : 0;
                int right = j < size - 1 ? prev[j + 1] : 0;
                curr[j] = ((left + right) % mod + stay) % mod;
            }
            for (int j = 0; j <= size; j ++) {
                prev[j] = curr[j];
            }
        }
        
        return curr[0];
    }
};