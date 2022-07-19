class Solution {
public:
    vector<vector<int>> generate(int rows) {
        vector<vector<int>> v;
        v.push_back({1});
        if (rows == 1) {
            return v;
        }
        
        v.push_back({1, 1});
        if (rows == 2) {
            return v;
        }
        
        while (rows -- > 2) {
            vector<int> next = {1};
            for (int i = 0; i < v.back().size() - 1; i ++) {
                next.push_back(v.back()[i] + v.back()[i + 1]);
            }
            next.push_back(1);
            v.push_back(next);
        }
        
        return v;
    }
};