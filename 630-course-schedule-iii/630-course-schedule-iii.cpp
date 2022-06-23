class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), [] (vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });
        
        priority_queue<int> pq;
        int n = courses.size();
        int duration = 0;
        
        for (int i = 0; i < n; i ++) {
            if (duration + courses[i][0] <= courses[i][1]) {
                duration += courses[i][0];
                pq.push(courses[i][0]);
                
            } else if (!pq.empty() && pq.top() > courses[i][0]) {
                duration -= pq.top() - courses[i][0];
                pq.push(courses[i][0]);
                pq.pop();
            }
        }
        
        return pq.size();
    }
};