class Solution {
public:
    int nthUglyNumber(int n) {
        if (n == 1) {
            return 1;
        }
        
        vector<int> ugly;
        ugly.push_back(1);
        
        int l2 = 0, l3 = 0, l5 = 0;
        
        while (ugly.size() < n) {
            int next = min({2 * ugly[l2], 3 * ugly[l3], 5 * ugly[l5]});
            ugly.push_back(next);
            
            if (next == 2 * ugly[l2]) {
                l2 ++;
            }
            if (next == 3 * ugly[l3]) {
                l3 ++;
            }
            if (next == 5 * ugly[l5]) {
                l5 ++;
            }
        }
        
        return ugly[n - 1];
    }
};