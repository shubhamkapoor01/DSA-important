class Solution {
private:
    void solve(vector<int>& candidates, int i, int target, vector<int>& curr, vector<vector<int>>& ans) {
        if (!target) {
            ans.push_back(curr);
            return;
        }
        
        if (target < 0) {
            return;
        }
        
        for (int j = i; j < candidates.size(); j ++) {
            if (j == i || candidates[j] != candidates[j - 1]) {
                curr.push_back(candidates[j]);
                solve(candidates, j + 1, target - candidates[j], curr, ans);
                curr.pop_back();
            }
        }
    }
    
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> curr;
        solve(candidates, 0, target, curr, ans);
        return ans;
    }
};