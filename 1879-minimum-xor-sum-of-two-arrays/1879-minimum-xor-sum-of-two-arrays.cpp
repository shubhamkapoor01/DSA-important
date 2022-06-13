class Solution {
private:
    int n;
    
    int solve(vector<int>& nums1, vector<int>& nums2, vector<int>& pos, int idx, int mask, vector<int>& dp) {
        if (mask == (1 << n) - 1) {
            return 0;
        }
        
        if (dp[mask] != -1) {
            return dp[mask];
        }
        
        int ans = INT_MAX;
        
        for (int i = 0; i < n; i ++) {
            if (mask & (1 << i)) {
                continue;
            }
            
            pos.push_back(i);
            ans = min(ans, (nums1[idx] xor nums2[i]) + solve(nums1, nums2, pos, idx + 1, mask | (1 << i), dp));
            pos.pop_back();
        }
        
        dp[mask] = ans;
        return ans;
    }
    
public:
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        n = nums1.size();
        vector<int> pos;
        vector<int> dp((1 << n), -1);
        return solve(nums1, nums2, pos, 0, 0, dp);
    }
};