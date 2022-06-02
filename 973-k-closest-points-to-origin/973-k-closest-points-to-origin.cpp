class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<long long, int>> pq;
        for (int i = 0; i < points.size(); i ++) {
            pq.push({points[i][0] * points[i][0] + points[i][1] * points[i][1], i});
            if (pq.size() > k) {
                pq.pop();
            }
        }
        vector<vector<int>> ans;
        while (pq.size()) {
            ans.push_back(points[pq.top().second]);
            pq.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};