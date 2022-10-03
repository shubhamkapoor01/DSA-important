class Solution {
public:
    int minCost(string s, vector<int>& v) {
        int n = v.size();
        int time = 0;
        for (int i = 0; i < n;) {
            int sum = 0;
            int mx = 0;
            int j = i;
            while (j < n && s[i] == s[j]) {
                mx = max(mx, v[j]);
                sum += v[j];
                j ++;
            }
            if (j - i > 1) {
                time += sum - mx;
            }
            i = j;
        }
        return time;
    }
};