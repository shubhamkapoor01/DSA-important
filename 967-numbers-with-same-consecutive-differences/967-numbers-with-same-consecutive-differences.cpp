class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> ans;
        
        queue<pair<int, int>> q;
        for (int i = 1; i <= 9; i ++) {
            q.push({i, 1});
        }
        
        while (!q.empty()) {
            int curr = q.front().first;
            int len = q.front().second;
            q.pop();
            
            if (len == n) {
                ans.push_back(curr);
            }
            
            int prev = curr % 10;
            int next1 = -1;
            int next2 = -1;
            
            if (prev - k >= 0) {
                next1 = prev - k;
            }
            if (prev + k < 10) {
                next2 = prev + k;
            }
            
            if (next1 != -1 && len < n) {
                q.push({curr * 10 + next1, len + 1});
            }
            if (next2 != next1 && next2 != -1 && len < n) {
                q.push({curr * 10 + next2, len + 1});
            }
        }
        
        return ans;
    }
};