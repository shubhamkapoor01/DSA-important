class Solution {
private:
    int findNonConflicting(vector<vector<int>>& events, int start) {
        int r = events.size();
        int l = 0;
        
        while (l <= r) {
            int m = l + (r - l) / 2;
            
            if (events[m][1] < start) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        
        return l - 1;
    }
    
public:
    static bool compare(vector<int>& x, vector<int>& y) {
        if (x[1] != y[1]) return x[1] < y[1];
        if (x[0] != y[0]) return x[0] < y[0];
        return x[2] > y[2];
    }
    
    int maxValue(vector<vector<int>>& events, int k) {
        int n = events.size();
        
        sort(events.begin(), events.end(), compare);
        vector<vector<int>> dp(n + 1, vector<int> (k + 1, 0));
        
        int profit = 0;
        for (int i = 1; i <= n; i ++) {
            profit = max(profit, events[i - 1][2]);
            dp[i][1] = profit;
        }
        
        for (int i = 1; i <= n; i ++) {
            int noConflict = findNonConflicting(events, events[i - 1][0]) + 1;
            for (int j = 2; j <= k; j ++) {
                dp[i][j] = max(dp[i - 1][j], events[i - 1][2] + dp[noConflict][j - 1]);
            }
        }
        
        // for (auto &i: dp) {
        //     for (auto &j: i) {
        //         cout << j << " ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;
        
        return dp[n][k];
    }
};