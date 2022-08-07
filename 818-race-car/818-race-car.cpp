class Solution {
public:
    int racecar(int target) {
        queue<pair<long long, pair<long long, long long>>> q;
        unordered_set<string> vis;
        q.push({0, {0, 1}});
        
        while (q.size()) {
            long long instructions = q.front().first;
            long long position = q.front().second.first;
            long long speed = q.front().second.second;
            q.pop();
            
            if (position == target) {
                return instructions;
            }
            
            string key = to_string(position) + " " + to_string(speed);
            
            if (vis.count(key) > 0) {
                continue;
            }
            
            vis.insert(key);
            q.push({instructions + 1, {position + speed, 2 * speed}});
            
            if (position + speed > target && speed > 0) {
                q.push({instructions + 1, {position, -1}});
                
            } else if (position + speed < target && speed < 0) {
                q.push({instructions + 1, {position, 1}});
            }
        }
        
        return -1;
    }
};