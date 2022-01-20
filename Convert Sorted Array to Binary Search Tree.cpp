class Solution {
public:
    TreeNode* solve(vector<int> &nums, int left, int right) {
        if (left > right) {
            return nullptr;
        }
        
        int mid = left + (right - left) / 2;
        
        TreeNode* root = new TreeNode(nums[mid]);
        root -> left = solve(nums, left, mid - 1);
        root -> right = solve(nums, mid + 1, right);
        
        return root;
    }
    
    TreeNode* sortedArrayToBST(vector<int> &nums) {
        return solve(nums, 0, nums.size() - 1);
    }
};
