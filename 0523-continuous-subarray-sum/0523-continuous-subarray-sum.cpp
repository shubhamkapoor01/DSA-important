class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = -1;
        
        int n = nums.size();
        int prefix_sum = 0;
        
        for (int i = 0; i < n; i ++) {
            prefix_sum = (prefix_sum + nums[i]) % k;
            
            if (mp.find(prefix_sum) == mp.end()) {
                mp[prefix_sum] = i;
            }
            
            if (i - mp[prefix_sum] > 1) {
                return true;
            }
        }
        
        return false;
    }
};