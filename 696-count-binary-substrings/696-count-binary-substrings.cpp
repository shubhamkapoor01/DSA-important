class Solution {
public:
    int countBinarySubstrings(string& s) {
        int n = s.size();
        int zeros = 0;
        int ones = 0;
        int cnt = 0;
        for (int i = 0; i < n; i ++) {
            int j = i;
            while (j < n && s[j] == s[i]) {
                if (s[j] == '0') {
                    zeros ++;
                } else {
                    ones ++;
                }
                j ++;
            }
            cnt += min(zeros, ones);
            if (s[i] == '0') {
                ones = 0;
            } else {
                zeros = 0;
            }
            i = j - 1;
        }
        return cnt;
    }
};


// 0 1 2 3 4 5 6 7
// 0 0 1 1 0 0 1 1
// 1 2 2 2 3 4 4 4
// 0 0 1 2 2 2 3 4