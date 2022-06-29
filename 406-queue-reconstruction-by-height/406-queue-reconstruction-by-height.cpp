class Solution {
public:
    static bool compare(vector<int>& a, vector<int>& b) {
        if (a[0] != b[0]) return a[0] > b[0];
        else return a[1] < b[1];
    }
    
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), compare);
        
        vector<vector<int>> ans;
        for (auto i: people) {
            ans.insert(ans.begin() + i[1], i);
        }
        
        return ans;
    }
};