class Solution {
public:
    string frequencySort(string s) {
        vector<int> v(256, 0);
        for (auto i: s) {
            v[i] ++;
        }
        
        priority_queue<pair<int, char>> pq;
        int ch = 0;
        
        for (auto i: v) {
            pq.push({i, char(ch)});
            ch ++;
        }
        
        string ans = "";
        while (!pq.empty()) {
            for (int i = 0; i < pq.top().first; i ++) {
                ans.push_back(pq.top().second);
            }
            pq.pop();
        }
        
        return ans;
    }
};