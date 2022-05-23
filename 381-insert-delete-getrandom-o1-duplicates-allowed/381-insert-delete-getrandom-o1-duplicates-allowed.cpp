class RandomizedCollection {
private:
    vector<int> v;
    unordered_map<int, unordered_set<int>> mp;
    
    
public:
    RandomizedCollection() {
    }
    
    bool insert(int val) {
        bool present = mp.find(val) != mp.end();
        v.push_back(val);
        mp[val].insert(v.size() - 1);
        return !present;
    }
    
    bool remove(int val) {
        if (mp.find(val) == mp.end()) {
            return false;
        }
        
        int last = v.back();
        int del = *mp[val].begin();
        
        if (last == val) {
            v.pop_back();
            mp[last].erase(v.size());
            if (mp[last].size() == 0) {
                mp.erase(last);
            }
            return true;
        }
        
        v.pop_back();
        v[del] = last;
        
        mp[last].insert(del);
        mp[last].erase(v.size());
        
        mp[val].erase(del);
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