class Solution {
private:
    int pass(vector<vector<int>>& r) {
        int m = r.size();
        int ans = 0;
        
        for (int i = 0; i < m - 1; i ++) {
            int h1 = r[i][1];
            int id1 = r[i][0];
            
            int h2 = r[i + 1][1];
            int id2 = r[i + 1][0];
            
            int h = h1 + abs(id2 - id1);
            
            if (h > h2) {
                h = h2 + (h - h2) / 2;
            }
            
            ans = max(ans, h);
            r[i + 1][1] = min(h, h2);
        }
        
        return ans;
    }
    
public:
    int maxBuilding(int n, vector<vector<int>>& r) {
        r.push_back({1, 0});
        r.push_back({n, n});
        
        sort(r.begin(), r.end());
        
        int leftToRight = pass(r);
        reverse(r.begin(), r.end());
        return pass(r);
    }
};