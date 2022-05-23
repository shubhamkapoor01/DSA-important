class RandomizedCollection {
private:
    vector<int> v;
    unordered_map<int, vector<int>> mp;
    
    
public:
    RandomizedCollection() {
    }
    
    bool insert(int val) {
        bool present = mp.find(val) != mp.end();
        v.push_back(val);
        mp[val].push_back(v.size() - 1);
        return !present;
    }
    
    bool remove(int val) {
        if (mp.find(val) == mp.end()) {
            return false;
        }
        
        int last = v.back();
        v.pop_back();
        v[mp[val].back()] = last;
        
        for (auto &i: mp[last]) {
            if (i == v.size()) {
                i = mp[val].back();
                break;
            }
        }
        
        mp[val].pop_back();
        if (mp[val].size() == 0) {
            mp.erase(val);
        }
        
        return true;
    }
    
    int getRandom() {
        return v[rand() % v.size()];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */