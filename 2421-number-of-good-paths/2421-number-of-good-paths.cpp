#define ll long long

class DSU {
private:
    unordered_map<ll, ll> parent;
    unordered_map<ll, ll> rank;

public:
    void makeNode (ll node) {
        if (parent.find(node) != parent.end()) {
            return;
        } else {
            parent[node] = node;
            rank[node] = 1;
        }
    }
    
    ll findParent(ll node) {
    	if (parent.find(node) == parent.end()) {
    		makeNode(node);
    	}
        if (node == parent[node]) {
            return node;
        }
        return parent[node] = findParent(parent[node]);
    }
    
    void unionByRank(ll a, ll b) {
        ll A = findParent(a);
        ll B = findParent(b);
        
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
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        ll n = vals.size();
        
        for (auto &i: edges) {
            i.push_back(max(vals[i[0]], vals[i[1]]));
            reverse(i.begin(), i.end());
        }
        
        unordered_map<ll, unordered_map<ll, ll>> mp;
        for (ll i = 0; i < n; i ++) {
            mp[i][vals[i]] = 1;
        }
        
        DSU dsu;
        
        sort(edges.begin(), edges.end());
        ll ans = n;
        
        for (auto &i: edges) {
            ll u = dsu.findParent(i[1]);
            ll v = dsu.findParent(i[2]);
            
            if (u == v) {
                continue;
            }
            
            ans += mp[u][i[0]] * mp[v][i[0]];
            
            dsu.unionByRank(u, v);
            mp[dsu.findParent(u)][i[0]] = mp[u][i[0]] + mp[v][i[0]];
        }
        
        return ans;
    }
};



































