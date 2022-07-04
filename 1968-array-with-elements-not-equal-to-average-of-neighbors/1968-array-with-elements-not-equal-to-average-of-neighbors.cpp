class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int r = n - 1;
        int l = 0;
        vector<int> ans;
        while (l <= r) {
            if (l <= (n - 1 - r)) {
                ans.push_back(nums[l ++]);
            } else {
                ans.push_back(nums[r --]);
            }
        }
        return ans;
    }
};


// 1 2 3 4 5;
// 1 5 2 4 3