class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int maxfreq = 0;
        for (auto i: nums) {
            maxfreq = max(maxfreq, ++ mp[i]);
        }
        
        vector<vector<int>> bucket(maxfreq + 1);
        for (auto i: mp) {
            bucket[i.second].push_back(i.first);
        }
        
        vector<int> ans;
        for (int i = maxfreq; i >= 1; i --) {
            for (int j = 0; j < bucket[i].size(); j ++) {
                ans.push_back(bucket[i][j]);
                k --;
                if (!k) {
                    break;
                }
            }
            if (!k) {
                break;
            }
        }
        
        return ans;
    }
};