class Skiplist {
private:
    unordered_map<int, int> mp;
    
public:
    Skiplist() {   
    }
    
    bool search(int target) {
        return mp.find(target) != mp.end();
    }
    
    void add(int num) {
        mp[num] ++;
    }
    
    bool erase(int num) {
        if (!search(num)) {
            return false;
        }
        mp[num] --;
        if (!mp[num]) {
            mp.erase(num);
        }
        return true;
    }
};

/**
 * Your Skiplist object will be instantiated and called as such:
 * Skiplist* obj = new Skiplist();
 * bool param_1 = obj->search(target);
 * obj->add(num);
 * bool param_3 = obj->erase(num);
 */