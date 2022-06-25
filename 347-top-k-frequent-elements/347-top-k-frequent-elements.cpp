// use it as unordered_map<int,int,custom_hash> mp;
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        /* http://xorshift.di.unimi.it/splitmix64.c */
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
 
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int, custom_hash> mp;
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