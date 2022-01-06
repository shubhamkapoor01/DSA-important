class Solution {
public:
    void solve(vector<int> nums, vector<int> curr, vector<bool> vis, vector<vector<int>>& ans) {
        if (curr.size() == nums.size()) {
            ans.push_back(curr);
            return;
        }
        
        for (int i = 0; i < nums.size(); i ++) {
            if (!vis[i]) {
                vis[i] = true;
                curr.push_back(nums[i]);
                solve(nums, curr, vis, ans);
                curr.pop_back();
                vis[i] = false;
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> vis(nums.size(), false);
        vector<vector<int>> ans;
        vector<int> curr;
        solve(nums, curr, vis, ans);
        return ans;
    }
};
