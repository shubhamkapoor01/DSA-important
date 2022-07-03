class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();
        vector<int> prefix(n, 0);
        
        for (int i = 0; i < n; i ++) {
            if (!i) prefix[i] = stones[i];
            else prefix[i] = prefix[i - 1] + stones[i];
        }
        
        int ans = prefix[n - 1];
        for (int i = n - 2; i > 0; i --) {
            ans = max(ans, prefix[i] - ans);
        }
        
        return ans;
    }
};