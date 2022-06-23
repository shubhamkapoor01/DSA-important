class Solution {
private:
    void solve(vector<int>& nums, vector<bool>& vis, vector<int>& curr, vector<vector<int>>& ans) {
        if (curr.size() == nums.size()) {
            ans.push_back(curr);
            return;
        }
        
        for (int i = 0; i < nums.size(); i ++) {
            if (!vis[i]) {
                vis[i] = true;
                curr.push_back(nums[i]);
                solve(nums, vis, curr, ans);
                curr.pop_back();
                vis[i] = false;
            }
        }
    }
    
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<int> curr;
        vector<vector<int>> ans;
        vector<bool> vis(n, false);
        solve(nums, vis, curr, ans);
        return ans;
    }
};