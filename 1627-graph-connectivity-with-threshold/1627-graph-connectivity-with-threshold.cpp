class Solution {
private:
    unordered_map<int, int> parent;
    unordered_map<int, int> rank;
    
    void dsu_init(int node) {
        if (parent.find(node) == parent.end()) {
            parent[node] = node;
            rank[node] = 0;
        }
    }
    
    int dsu_parent(int node) {
        if (parent[node] == node) {
            return node;
        } else {
            return parent[node] = dsu_parent(parent[node]);
        }
    }
    
    void dsu_union(int node1, int node2) {
        dsu_init(node1);
        dsu_init(node2);
        
        node1 = dsu_parent(node1);
        node2 = dsu_parent(node2);
        if (node1 == node2) {
            return;
        }
        
        if (rank[node1] < rank[node2]) {
            swap(node1, node2);
        }
        
        parent[node2] = node1;
        if (rank[node1] == rank[node2]) {
            rank[node1] ++;
        }
    }
    
public:
    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
        for (int i = 1; i <= n; i ++) {
            dsu_init(i);
        }
        
        for (int i = threshold + 1; i <= n; i ++) {
            for (int j = 2 * i; j <= n; j += i) {
                dsu_union(i, j);
            }
        }
        
        vector<bool> ans;
        int q = queries.size();
        for (int i = 0; i < q; i ++) {
            ans.push_back(dsu_parent(queries[i][0]) == dsu_parent(queries[i][1]));
        }
        return ans;
    }
};