class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, bool> m;
        int n = nums.size();
        int ans = 0;
        
        for (int i = 0; i < n; i ++) {
            m[nums[i]] = true;
        }
        
        for (int i = 0; i < n; i ++) {
            if (m.find(nums[i] - 1) == m.end()) {
                int cnt = 1;
                int curr = nums[i] + 1;
                
                while (m.find(curr) != m.end()) {
                    curr ++;
                    cnt ++;
                }
                
                ans = max(ans, cnt);
            }
        }
        
        return ans;
    }
};
