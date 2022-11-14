class DSU {
private:
    unordered_map<int, int> parent;
    unordered_map<int, int> rank;
    
public:
    DSU (int sz) {
        for (int i = 0; i < sz; i ++) {
            parent[i] = i;
            rank[i] = 1;
        }
    }
    
    int findParent(int x) {
        if (x == parent[x]) {
            return x;
        }
        return parent[x] = findParent(parent[x]);
    }
    
    void unionByRank(int a, int b) {
        int A = findParent(a);
        int B = findParent(b);
        
        if (A == B) {
            return;
        }
        
        if (rank[A] < rank[B]) {
            swap(A, B);
        }
        
        parent[B] = A;
        
        if (rank[A] == rank[B]) {
            rank[A] ++;
        }
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        DSU dsu(n);
        
        unordered_map<int, vector<int>> rows;
        unordered_map<int, vector<int>> cols;
        
        for (int i = 0; i < n; i ++) {
            rows[stones[i][0]].push_back(i);
            cols[stones[i][1]].push_back(i);
        }
        
        for (auto row = rows.begin(); row != rows.end(); row ++) {
            for (auto node = 1; node < row -> second.size(); node ++) {
                dsu.unionByRank(row -> second[0], row -> second[node]);
            }
        }
        
        for (auto col = cols.begin(); col != cols.end(); col ++) {
            for (auto node = 1; node < col -> second.size(); node ++) {
                dsu.unionByRank(col -> second[0], col -> second[node]);
            }
        }
        
        int removed = n;
        for (auto i = 0; i < stones.size(); i ++) {
            if (i == dsu.findParent(i)) {
                removed --;
            }
        }
        
        return removed;
    }
};