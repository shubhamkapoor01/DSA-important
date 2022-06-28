class Solution {
public:
    int minDeletions(string s) {
        vector<int> v(26, 0);
        for (auto i: s) {
            v[i - 'a'] ++;
        }
        
        unordered_map<int, int> mp;
        int cnt = 0;
        
        for (auto i: v) {
            // cout << i << " ";
            
            if (!i) {
                continue;
            }
            
            if (mp.find(i) == mp.end()) {
                mp[i] ++;
                
            } else {
                int curr = i;
                while (mp.find(curr) != mp.end()) {
                    curr --;
                    cnt ++;
                }
                
                if (curr) {
                    mp[curr] ++;
                }
            }
        }
        
        // cout << endl;
        return cnt;
    }
};

















