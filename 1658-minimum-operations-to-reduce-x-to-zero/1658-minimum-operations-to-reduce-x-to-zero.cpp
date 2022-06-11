class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        unordered_map<int, int> mp;
        int n = nums.size();
        int sum = 0;
        
        mp[0] = -1;
        for (int i = 0; i < n; i ++) {
            sum += nums[i];
            mp[sum] = i;
        }
        
        int suffix = 0;
        int steps = mp.find(x) != mp.end() ? mp[x] + 1 : INT_MAX;
        
        for (int i = n - 1; i >= 0; i --) {
            suffix += nums[i];
            
            if (mp.find(x - suffix) != mp.end() && mp[x - suffix] < i) {
                steps = min(steps, mp[x - suffix] + 1 + n - i);
            }
        }
        
        return steps == INT_MAX ? -1 : steps;
    }
};

