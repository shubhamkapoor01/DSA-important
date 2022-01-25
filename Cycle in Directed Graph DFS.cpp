class Solution {
public:
    bool hasCycle(vector<vector<int>>& graph, int start, vector<bool>& vis, vector<bool>& cyc) {
        vis[start] = true;
        cyc[start] = true;
        
        for (auto i: graph[start]) {
            if (!vis[i] && hasCycle(graph, i, vis, cyc)) {
                return true;
            }
            if (cyc[i]) {
                return true;
            }
        }
        
        cyc[start] = false;
        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        for (int i = 0; i < prerequisites.size(); i ++) {
            graph[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        
        vector<bool> vis(numCourses, false);
        vector<bool> cyc(numCourses, false);
        
        for (int i = 0; i < numCourses; i ++) {
            if (!vis[i] && hasCycle(graph, i, vis, cyc)) {
                return false;
            }
        }
        return true;
    }
};
