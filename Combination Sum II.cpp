class Solution {
public:
    void solve(vector<int>& arr, int target, int sum, int idx, vector<int> curr, vector<vector<int>>& ans) {        
        if (sum == target) {
            ans.push_back(curr);
            return;
        }
        
        if (sum > target || idx >= arr.size()) {
            return;
        }
        
        curr.push_back(arr[idx]);
        solve(arr, target, sum + arr[idx], idx + 1, curr, ans);
        curr.pop_back();
        
        while (idx + 1 < arr.size() && arr[idx] == arr[idx + 1]) {
            idx ++;
        }
        
        solve(arr, target, sum, idx + 1, curr, ans);
        return;
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> curr;
        solve(candidates, target, 0, 0, curr, ans);
        return ans;
    }
};
