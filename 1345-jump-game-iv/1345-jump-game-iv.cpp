class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        
        unordered_map<int, unordered_set<int>> mp;
        for (int i = 0; i < n; i ++) {
            mp[arr[i]].insert(i);
        }
        
        vector<int> vis(n, false);
        queue<pair<int, int>> q;
        q.push({0, 0});
        vis[0] = true;
        
        while (!q.empty()) {
            int index = q.front().first;
            int steps = q.front().second;
            
            q.pop();
            
            if (index == n - 1) {
                return steps;
            }
            
            if (index - 1 >= 0 && !vis[index - 1]) {
                q.push({index - 1, steps + 1});
                vis[index - 1] = true;
            }
            
            if (index + 1 < n && !vis[index + 1]) {
                q.push({index + 1, steps + 1});
                vis[index + 1] = true;
            }
            
            for (auto idx: mp[arr[index]]) {
                if (!vis[idx]) {
                    q.push({idx, steps + 1});
                    vis[idx] = true;
                }
            }
            mp.erase(arr[index]);
        }
        
        return -1;
    }
};