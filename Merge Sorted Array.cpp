class Solution {
public:
    void merge(vector<int>& a, int m, vector<int>& b, int n) {
        int gap = (m + n) / 2;
        bool done = false;
        
        for (int i = 0; i < n; i ++) {
            a[m + i] = b[i];
        }
        
        while (gap >= 1) {
            int i = 0;
            int j = gap;
            
            if (gap == 1) {
                done = true;
            }
            
            while (j < m + n) {
                if (a[i] > a[j]) {
                    int t = a[i];
                    a[i] = a[j];
                    a[j] = t;
                }
                i ++;
                j ++;
            }
            gap = (gap + 1) / 2;
            
            if (done) {
                break;
            }
        }
        
        return;
    }
};
