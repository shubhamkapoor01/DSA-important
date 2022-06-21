class Solution {
private:
    void solve(vector<int>& nums, int i, vector<int>& curr, vector<vector<int>>& ans) {
        ans.push_back(curr);
        
        for (int j = i; j < nums.size(); j ++) {
            if (j != i && nums[j] == nums[j - 1]) {
                continue;
            }
            
            curr.push_back(nums[j]);
            solve(nums, j + 1, curr, ans);
            curr.pop_back();
        }
    }
    
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> curr;
        solve(nums, 0, curr, ans);
        return ans;
    }
};