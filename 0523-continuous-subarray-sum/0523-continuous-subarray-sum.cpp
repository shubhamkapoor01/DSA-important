class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = -1;
        
        int n = nums.size();
        int sum = 0;
        
        for (int i = 0; i < n; i ++) {
            if (nums[i] == 0) {
                if (i + 1 < n && nums[i + 1] == 0) {
                    return true;
                }
                continue;
            }
            
            sum += nums[i];
            
            if (mp.find(sum % k) != mp.end()) {
                if (i - mp[sum % k] > 1) {
                    return true;
                }
                
            } else {
                mp[sum % k] = i;
            }
        }
        
        return false;
    }
};