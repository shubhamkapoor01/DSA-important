class Solution {
public:
    int reinitializePermutation(int n) {
        int oneidx = 1;
        int count = 0;
        
        while (oneidx != 1 || count == 0) {
            if (oneidx % 2) {
                oneidx = n / 2 + (oneidx - 1) / 2;
            } else {
                oneidx = oneidx / 2;
            }
            count ++;
        }
        
        return count;
    }
};