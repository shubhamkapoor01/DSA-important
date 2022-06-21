class Solution {
private:
    void solve(vector<int>& nums, int i, int p, vector<int>& curr, vector<vector<int>>& ans) {
        if (i == nums.size()) {
            ans.push_back(curr);
            return;
        }
        
        solve(nums, i + 1, 0, curr, ans);
        if (i > 0 && nums[i] == nums[i - 1] && !p) {
            return;
        }
        
        curr.push_back(nums[i]);
        solve(nums, i + 1, 1, curr, ans);
        curr.pop_back();
        return;
    }
    
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> curr;
        solve(nums, 0, 0, curr, ans);
        return ans;
    }
};