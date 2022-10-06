class TimeMap {
    unordered_map<string, vector<pair<int, string>>> container;
    
public:
    void set(string key, string value, int timestamp) {
        container[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if (container.find(key) == container.end()) {
            return "";
        }
        
        int r = container[key].size() - 1;
        int l = 0;
        
        while (l <= r) {
            int m = l + (r - l) / 2;
            
            if (container[key][m].first <= timestamp) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        
        if (l == 0) {
            return "";
        }
        
        return container[key][l - 1].second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */