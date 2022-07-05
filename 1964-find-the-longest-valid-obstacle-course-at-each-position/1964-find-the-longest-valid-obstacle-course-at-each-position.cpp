class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        int n = obstacles.size();
        vector<int> ans;
        vector<int> lis;
        for (int i = 0; i < n; i ++) {
            if (!lis.size() || lis.back() <= obstacles[i]) {
                lis.push_back(obstacles[i]);
                ans.push_back(lis.size());
            } else {
                int idx = upper_bound(lis.begin(), lis.end(), obstacles[i]) - lis.begin();
                if (lis[idx] == obstacles[i]) {
                    lis[idx + 1] = obstacles[i];
                    ans.push_back(idx + 2);
                } else {
                    lis[idx] = obstacles[i];
                    ans.push_back(idx + 1);
                }
            }
            // cout << i << " -> ";
            // for (auto i: lis) {
            //     cout << i << " ";
            // }
            // cout << endl;
        }
        // cout << endl;
        return ans;
    }
};