class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        vector<int> stack;
        for (int i = 0; i < nums.size(); i ++) {
            while (stack.size() && stack.size() - 1 + nums.size() - i >= k && stack.back() > nums[i]) {
                stack.pop_back();
            }
            if (stack.size() < k) {
                stack.push_back(nums[i]);
            }
        }
        return stack;
    }
};