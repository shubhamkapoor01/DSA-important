class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m == 1 || n == 1) return 1;
        if(n > m) return uniquePaths(n, m);
        
        m --, n--;
        
        long res = 1;
        for(int i = m + 1, j = 1; i <= m + n; i++, j++) {
            res *= i;
            res /= j;
        }
        
        return res;
    }
};