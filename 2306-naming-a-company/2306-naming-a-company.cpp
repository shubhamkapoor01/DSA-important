class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        vector<unordered_set<string>> group(26);
        for (auto &i: ideas) {
            group[i[0] - 'a'].insert(i.substr(1));
        }
        
        long long total = 0;
        
        for (int i = 0; i < 26; i ++) {
            for (int j = i + 1; j < 26; j ++) {
                long long curri = 0LL;
                long long currj = 0LL;
                
                for (auto &c: group[i]) {
                    if (group[j].find(c) == group[j].end()) {
                        curri ++;
                    }
                }
                
                for (auto &c: group[j]) {
                    if (group[i].find(c) == group[i].end()) {
                        currj ++;
                    }
                }
                
                total += 2 * curri * currj;
            }
        }
        
        return total;
    }
};