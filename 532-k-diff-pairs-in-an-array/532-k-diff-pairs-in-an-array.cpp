class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        set<pair<int, int>> st;
        
        int n = nums.size();
        int cnt = 0;
        
        for (int i = 0; i < n; i ++) {
            if (mp.find(nums[i] - k) != mp.end() && st.find({nums[i], nums[i] - k}) == st.end()) {
                st.insert({nums[i], nums[i] - k});
                st.insert({nums[i] - k, nums[i]});
                cnt ++;
            }
            mp[nums[i]] ++;
        }
        
        mp.clear();
        for (int i = n - 1; i >= 0; i --) {
            if (mp.find(nums[i] - k) != mp.end() && st.find({nums[i], nums[i] - k}) == st.end()) {
                st.insert({nums[i], nums[i] - k});
                st.insert({nums[i] - k, nums[i]});
                cnt ++;
            }
            mp[nums[i]] ++;
        }
        
        return cnt;
    }
};