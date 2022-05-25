class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int water = 0;
        
        int maxr = 0;
        int maxl = 0;
        int r = n - 1;
        int l = 0;

        while (l <= r) {
            if (height[l] <= height[r]) {
                water += l == 0 ? 0 : max(0, maxl - height[l]);
                maxl = max(maxl, height[l]);
                l ++;
                
            } else {
                water += r == n - 1 ? 0 : max(0, maxr - height[r]);
                maxr = max(maxr, height[r]);
                r --;
            }
        }
        
        return water;
    }
};
