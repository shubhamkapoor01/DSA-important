class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<bool> vis(numCourses, false);
        vector<int> indegree(numCourses, 0);
        vector<int> ans;
        
        for (int i = 0; i < prerequisites.size(); i ++) {
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]] ++;
        }
        
        queue<int> q;
        for (int i = 0; i < numCourses; i ++) {
            if (indegree[i] == 0) {
                vis[i] = true;
                q.push(i);
            }
        }
        
        int numIterations = 0;
        while (!q.empty()) {
            int front = q.front();
            ans.push_back(front);
            q.pop();
            
            for (auto it: graph[front]) {
                indegree[it] --;
                
                if (!indegree[it]) {
                    vis[it] = true;
                    q.push(it);
                }
            }
            
            numIterations ++;
        }
        
        
        if (numIterations < numCourses) {
            return {};
        }
        return ans;
    }
};
