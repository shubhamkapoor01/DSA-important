class Solution {
private:
    map<vector<int>, int> mp;   
    int side;
    
    bool solve(vector<int>& matchsticks, int i = 0, int a = 0, int b = 0, int c = 0, int d = 0) {
        if (a > side || b > side || c > side || d > side) {
            return false;
        }
        
        if (i == matchsticks.size()) {
            return a == b && a == c && a == d;
        }
        
//         if (mp.find({i, a, b, c, d}) != mp.end()) {
//             return mp[{i, a, b, c, d}];
//         }
        
        return solve(matchsticks, i + 1, a + matchsticks[i], b, c, d) || 
                              solve(matchsticks, i + 1, a, b + matchsticks[i], c, d) || 
                              solve(matchsticks, i + 1, a, b, c + matchsticks[i], d) ||
                              solve(matchsticks, i + 1, a, b, c, d + matchsticks[i]);
        
        // return mp[{i, a, b, c, d}];
    }
    
public:
    bool makesquare(vector<int>& matchsticks) {
        sort(matchsticks.begin(), matchsticks.end(), greater<int>());
        int n = matchsticks.size();
        int sum = 0;
        for (auto &i: matchsticks) {
            sum += i;
        }
        if (sum % 4) {
            return false;
        }
        side = sum / 4;
        return solve(matchsticks);
    }
};