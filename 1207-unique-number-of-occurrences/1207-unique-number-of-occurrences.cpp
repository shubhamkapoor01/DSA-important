class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> mp;       
        unordered_set<int> st;                     
        int n = arr.size();
        
        for (int i = 0; i < n; i ++) mp[arr[i]] ++;        
        for (auto it: mp) st.insert(it.second);

        if (mp.size() == st.size()) return true;
        else return false;
    }
};