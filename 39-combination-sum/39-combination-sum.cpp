class Solution {
private:
    void solve(vector<int>& candidates, int idx, int target, vector<int>& curr, vector<vector<int>>& ans) {
        if (idx == candidates.size() || target < 0) {
            if (!target) {
                ans.push_back(curr);
            }
            return;
        }
        
        solve(candidates, idx + 1, target, curr, ans);
        curr.push_back(candidates[idx]);
        solve(candidates, idx, target - candidates[idx], curr, ans);
        curr.pop_back();
        return;
    }
    
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        solve(candidates, 0, target, curr, ans);
        return ans;
    }
};