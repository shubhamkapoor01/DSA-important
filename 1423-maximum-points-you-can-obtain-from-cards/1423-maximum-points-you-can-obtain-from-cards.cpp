class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int n = nums.size();
        int rolling = 0;
        
        for (int i = 0; i < k; i ++) {
            rolling += nums[i];
        }
        
        int total = rolling;
        
        for (int i = 0; i < k; i ++) {
            rolling -= nums[k - i - 1];
            rolling += nums[n - i - 1];
            total = max(total, rolling);
        }
        
        return total;
    }
};