class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int n = plantTime.size();
        vector<pair<int, int>> v;
        
        for (int i = 0; i < n; i ++) {
            v.push_back({ growTime[i], plantTime[i] });
        }
        
        sort(v.begin(), v.end(), greater<pair<int, int>>());
        
        vector<pair<int, pair<int, int>>> t(n);
        t[0] = { 0, { v[0].second, v[0].first + v[0].second }};
        int ans = 0;
        
        for (int i = 1; i < n; i ++) {
            t[i].first = t[i - 1].second.first + 1;
            t[i].second.first = t[i - 1].second.first + v[i].second;
            t[i].second.second = t[i - 1].second.first + v[i].second + v[i].first;
        }
        
        for (int i = 0; i < n; i ++) {
            ans = max(ans, t[i].second.second);
        }
        
        return ans;
    }
};