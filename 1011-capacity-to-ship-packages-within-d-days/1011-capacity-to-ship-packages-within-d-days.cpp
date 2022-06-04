class Solution {
private:
    bool possible(vector<int>& weights, int days, int limit) {
        int n = weights.size();
        int curr = 0;
        for (int i = 0; i < n; i ++) {
            curr += weights[i];
            if (curr > limit) {
                curr = weights[i];
                days --;
            }
        }
        if (curr) days --;
        return days >= 0;
    }
    
public:
    int shipWithinDays(vector<int>& weights, int days) {
        // sort(weights.begin(), weights.end());
        int n = weights.size();
        int ans = 0;
        int l = 0;
        int r = 0;
        
        for (auto &weight: weights) {
            l = max(l, weight);
            r += weight;
        }
        
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (possible(weights, days, m)) {
                r = m - 1;
                ans = m;
            } else {
                l = m + 1;
            }
        }
        
        return ans;
    }
};