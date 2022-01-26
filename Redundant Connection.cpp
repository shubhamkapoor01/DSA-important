class Solution {
public:
    int Find(int n, vector<int>& par) {
        int p = par[n];
        while (p != par[p]) {
            par[p] = par[par[p]];
            p = par[p];
        }
        return p;
    }
    
    bool Union(int n1, int n2, vector<int>& rank, vector<int>& par) {
        int p1 = Find(n1, par);
        int p2 = Find(n2, par);
        
        if (p1 == p2) {
            return false;
        }
        
        if (rank[p1] > rank[p2]) {
            par[p2] = p1;
            rank[p1] += rank[p2];
            
        } else {
            par[p1] = p2;
            rank[p2] += rank[p1];
        }
        
        return true;
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> rank(n + 1, 1);
        vector<int> par(n + 1);
        
        for (int i = 0; i <= n; i ++) {
            par[i] = i;
        }
        
        for (int i = 0; i < n; i ++) {
            if (!Union(edges[i][0], edges[i][1], rank, par)) {
                return {edges[i][0], edges[i][1]};
            }
        }
        
        return {-1, -1};
    }
};
