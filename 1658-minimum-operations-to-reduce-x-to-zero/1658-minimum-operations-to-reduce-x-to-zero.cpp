class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int sum = 0;
        for (auto num: nums) {
            sum += num;
        }
        
        if (x > sum) {
            return -1;
        }
        
        int steps = INT_MAX;
        int curr = 0;
        int we = 0;
        int ws = 0;
        
        while (we < n) {
            curr += nums[we];
            
            while (curr > sum - x) {
                curr -= nums[ws];
                ws ++;
            }
            
            if (curr == sum - x) {
                steps = min(steps, n - (we - ws + 1));
            }
            we ++;
        }
        
        return steps != INT_MAX ? steps : -1;
    }
};

