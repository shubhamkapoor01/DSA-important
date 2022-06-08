class Solution {
public:
    int removePalindromeSub(string s) {
        int r = s.size() - 1;
        int l = 0;
        while (l < r) {
            if (s[l] == s[r]) {
                l ++;
                r --;
            } else {
                return 2;
            }
        }
        return 1;
    }
};