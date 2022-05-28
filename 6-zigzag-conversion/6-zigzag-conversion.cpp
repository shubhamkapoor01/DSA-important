class Solution {
public:
    string convert(string s, int n) {
        if (n == 1) {
            return s;
        }
        
        vector<string> v(n);
        int row = 0;
        int turn = 1;
        for (auto &i: s) {
            v[row].push_back(i);
            
            if (row == n - 1) {
                turn = -1;
            } else if (row == 0) {
                turn = 1;
            }
            
            if (turn == 1) {
                row ++;
            } else {
                row --;
            }
        }
        string ans;
        for (auto &row: v) {
            for (auto &ch: row) {
                ans.push_back(ch);
            }
        }
        return ans;
    }
};