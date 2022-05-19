class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& persons) {
        vector<pair<int, pair<char, int>>> v;
        for (int i = 0; i < flowers.size(); i ++) {
            v.push_back({flowers[i][0], {'a', 0}});
            v.push_back({flowers[i][1], {'z', 0}});
        }
        
        for (int i = 0; i < persons.size(); i ++) {
            v.push_back({persons[i], {'p', i}});
        }
        
        sort(v.begin(), v.end());
        
        vector<int> ans(persons.size());
        int currCount = 0;
        
        for (int i = 0; i < v.size(); i ++) {
            if (v[i].second.first == 'a') {
                currCount ++;
                
            } else if (v[i].second.first == 'z') {
                currCount --;
                
            } else {
                ans[v[i].second.second] = currCount;
            }
        }
        
        return ans;
    }
};