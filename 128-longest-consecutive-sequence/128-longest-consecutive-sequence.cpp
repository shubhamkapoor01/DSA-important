class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> mp;
        int n = nums.size();
        int lcs = 0;
        
        for (auto &i: nums) {
            mp.insert(i);
        }
        
        for (int i = 0; i < n; i ++) {
            if (mp.find(nums[i] - 1) != mp.end()) {
                continue;
            }
            
            int t = nums[i] + 1;
            int c = 1;
            
            while (mp.find(t) != mp.end()) {
                t ++;
                c ++;
            }
            
            lcs = max(lcs, c);
        }
                       
        return lcs;
    }
};