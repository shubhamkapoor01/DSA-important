class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n + 1, 0);
        for (int i = 0; i <= n; i ++) {
            int j = i;
            while (j) {
                if (j % 2) ans[i] ++;
                j /= 2;
            }
        }
        return ans;
    }
};