class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        
        int mod = 1000000007;
        int n = verticalCuts.size();
        int m = horizontalCuts.size();
        int maxVe = w - verticalCuts[n - 1];
        int maxHz = h - horizontalCuts[m - 1];
        
        for (int i = 0; i < n; i ++) {
            int diffVe = verticalCuts[i] - (i == 0 ? 0 : verticalCuts[i - 1]);
            maxVe = max(maxVe, diffVe);
        }
        
        for (int i = 0; i < m; i ++) {
            int diffHz = horizontalCuts[i] - (i == 0 ? 0 : horizontalCuts[i - 1]);
            maxHz = max(maxHz, diffHz);
        }
        
        return ((long)maxHz % mod * (long)maxVe % mod) % mod;
    }
};