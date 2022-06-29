class LockingTree {
    unordered_map<int, int> locked;
    vector<vector<int>> tree;
    vector<int> parent;
    int size;
    
    void dfs(vector<vector<int>>& tree, int node, int root, vector<int>& lockedChildren) {
        if (node != root && locked.find(node) != locked.end()) {
            lockedChildren.push_back(node);
        }
        for (auto child: tree[node]) {
            dfs(tree, child, root, lockedChildren);
        }
    }
        
public:
    LockingTree(vector<int>& parent) {
        this -> parent = parent;
        this -> size = parent.size();
        this -> tree = vector<vector<int>> (size);
        for (int i = 1; i < size; i ++) {
            tree[parent[i]].push_back(i);
        }
    }
    
    bool lock(int num, int user) {
        if (locked.find(num) != locked.end()) {
            return false;
        }
        locked[num] = user;
        return true;
    }
    
    bool unlock(int num, int user) {
        if (locked.find(num) == locked.end() || locked[num] != user) {
            return false;
        }
        locked.erase(num);
        return true;
    }
    
    bool upgrade(int num, int user) {
        if (locked.find(num) != locked.end()) {
            return false;
        }
        
        bool lockedAncestors = false;
        int node = num;
        while (node != -1 && parent[node] != node) {
            node = parent[node];
            if (locked.find(node) != locked.end()) {
                lockedAncestors = true;
                break;
            }
        }
        if (lockedAncestors) {
            return false;
        }
        
        vector<int> lockedChildren;
        dfs(tree, num, num, lockedChildren);
        if (!lockedChildren.size()) {
            return false;
        }
        
        cout << num << " -> ";
        for (int i = 0; i < lockedChildren.size(); i ++) {
            cout << lockedChildren[i] << " ";
        }
        cout << endl;
        
        locked[num] = user;
        for (auto child: lockedChildren) {
            locked.erase(child);
        }
        return true;
    }
};

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree* obj = new LockingTree(parent);
 * bool param_1 = obj->lock(num,user);
 * bool param_2 = obj->unlock(num,user);
 * bool param_3 = obj->upgrade(num,user);
 */