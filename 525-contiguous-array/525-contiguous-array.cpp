class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> mp;
        mp[0] = -1;
        
        int n = nums.size();
        int curr = 0;
        int len = 0;
        
        for (int i = 0; i < n; i ++) {
            if (nums[i]) {
                curr ++;
            } else {
                curr --;
            }
            
            if (mp.find(curr) == mp.end()) {
                mp[curr] = i;
            } else {
                len = max(len, i - mp[curr]);
            }
        }
        
        return len;
    }
};