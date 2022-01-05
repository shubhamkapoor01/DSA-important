class Solution {
public:
    void solve(vector<int> &nums, vector<vector<int>> &ans, vector<int> &curr, int i) {
        ans.push_back(curr);
        
        for (int idx = i; idx < nums.size(); idx ++) {   
            if (idx != i && nums[idx - 1] == nums[idx]) {
                continue;
            }
            
            curr.push_back(nums[idx]);
            solve(nums, ans, curr, idx + 1);
            curr.pop_back();
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> curr;
        solve(nums, ans, curr, 0);
        return ans;
    }
};
