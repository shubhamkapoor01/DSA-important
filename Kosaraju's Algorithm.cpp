#include<bits/stdc++.h>

void dfs(vector<vector<int>>& graph, int root, stack<int>& st, vector<bool>& vis) {
    vis[root] = true;
    for (auto i: graph[root]) {
        if (!vis[i]) {
            dfs(graph, i, st, vis);
        }
    }
    st.push(root);
    return;
}

void dfsT(vector<vector<int>>& graph, int root, stack<int>& st, vector<bool>& vis, vector<int>& temp) {
    temp.push_back(root);
    vis[root] = true;
    
    for (auto i: graph[root]) {
        if (!vis[i]) {
        	dfsT(graph, i, st, vis, temp);
        }
    }
}

vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>> &edges) {
    vector<vector<int>> graph(n);
    for (int i = 0; i < edges.size(); i ++) {
        graph[edges[i][0]].push_back(edges[i][1]);
    }
    
    stack<int> st;
    vector<bool> vis(n, false);
    
    for (int i = 0; i < n; i ++) {
        if (!vis[i]) {
            dfs(graph, i, st, vis);
        }
    }
    
    vector<vector<int>> graphT(n);    
    for (int i = 0; i < n; i ++) {
        vis[i] = false;
        for (int j = 0; j < graph[i].size(); j ++) {
        	graphT[graph[i][j]].push_back(i);
        }
    }
    
    vector<vector<int>> ans;
    while (!st.empty()) {
        int x = st.top();
        st.pop();
        
        if (!vis[x]) {
            vector<int> temp;
            dfsT(graphT, x, st, vis, temp);
            ans.push_back(temp);
        }
    }
    
    return ans;
}
