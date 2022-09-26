class Solution {
private:
    unordered_map<int, int> parent;
    unordered_map<int, int> rank;
    
    void dsu_make_node(int node) {
        parent[node] = node;
        rank[node] = 0;
    }
    
    int dsu_find_parent(int node) {
        if (parent[node] == node) {
            return node;
        } else {
            return parent[node] = dsu_find_parent(parent[node]);
        }
    }
    
    void dsu_union(int node1, int node2) {
        node1 = dsu_find_parent(node1);
        node2 = dsu_find_parent(node2);
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
    bool equationsPossible(vector<string>& equations) {
        int n = equations.size();
        for (int i = 0; i < n; i ++) {
            if (parent.find(equations[i][0] - 'a') == parent.end()) {
                dsu_make_node(equations[i][0] - 'a');
            }
            if (parent.find(equations[i][3] - 'a') == parent.end()) {
                dsu_make_node(equations[i][3] - 'a');
            }
            if (equations[i][1] == '=') {
                dsu_union(equations[i][0] - 'a', equations[i][3] - 'a');
            }
        }
        
        for (int i = 0; i < n; i ++) {
            if (equations[i][1] == '=') {
                continue;
            }
            if (dsu_find_parent(equations[i][0] - 'a') == dsu_find_parent(equations[i][3] - 'a')) {
                return false;
            }
        }
        
        return true;
    }
};