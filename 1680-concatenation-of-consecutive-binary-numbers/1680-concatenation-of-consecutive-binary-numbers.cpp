class Solution {
public:
    int concatenatedBinary(int n) {
        long mod = 1e9+7;
        long ans = 0;
        long len = 0;
        
        for (int i = 1; i <= n; ++i) {
            if ((i & (i - 1)) == 0) {
                len ++;
            }
            ans = ((ans << len) % mod + i) % mod;
        }
        
        return ans;
    }
};