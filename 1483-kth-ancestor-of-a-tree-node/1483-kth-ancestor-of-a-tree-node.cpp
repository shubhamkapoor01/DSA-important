class TreeAncestor {
private:
    vector<vector<int>> ancestors;
    vector<int> depth;
    int log;
    
public:
    TreeAncestor(int n, vector<int>& parent) {
        ancestors = vector<vector<int>> (n, vector<int> (log2(n) + 1));    
        depth = vector<int> (n, 0);
        
        parent[0] = 0;
        log = log2(n) + 1;
        
        for (int i = 0; i < n; i ++) {
            ancestors[i][0] = parent[i];
            if (i) {
                depth[i] = depth[parent[i]] + 1;
            }
        }
            
        for (int j = 1; j < log; j ++) {
            for (int i = 0; i < n; i ++) {
                ancestors[i][j] = ancestors[ancestors[i][j - 1]][j - 1];
            }
        }
        
        for (int i = 0; i < n; i ++) {
            if (i) {
                depth[i] = depth[parent[i]] + 1;
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        if (k > depth[node]) {
            return -1;
        }
        
        for (int j = 0; j < log; j ++) {
            if (k & (1 << j)) {
                node = ancestors[node][j];
            }
        }
        
        return node;
    }
};


/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */