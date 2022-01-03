class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        
        for (int i = 0; i < n; i ++) {
            if (nums[i] == 0) {
                continue;
            }
            
            int curr = 0;
            int t = nums[i];
            while (i < n && nums[i] == t) {
                curr ++;
                i ++;
            }
            
            ans = max(ans, curr);
        }
        
        return ans;
    }
};
