class Solution {
public:
    void solve(vector<int>& arr, int target, int sum, int idx, vector<int> curr, vector<vector<int>>& ans) {
        if (sum > target || idx >= arr.size()) {
            return;
        }
        
        if (sum == target) {
            ans.push_back(curr);
            return;
        }
        
        solve(arr, target, sum, idx + 1, curr, ans);
        curr.push_back(arr[idx]);
        solve(arr, target, sum + arr[idx], idx, curr, ans);
        curr.pop_back();
        return;
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        solve(candidates, target, 0, 0, curr, ans);
        return ans;
    }
};
