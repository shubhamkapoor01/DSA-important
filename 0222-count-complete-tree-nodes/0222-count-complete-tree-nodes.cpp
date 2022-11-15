/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int getHeight(TreeNode* root) {
        if (!root) return 0;
        return 1 + getHeight(root -> left);
    }
    
    bool existsKthNode(TreeNode* root, int k, int h) {
        if (!root) return false;
        if (k == 1 && h == 1) return true;
        if (k > (1 << (h - 2))) return existsKthNode(root -> right, k - (1 << (h - 2)), h - 1);
        else return existsKthNode(root -> left, k, h - 1);
    }
    
    int countNodes(TreeNode* root) {
        int height = getHeight(root);
        if (!height) return 0;
        int ans;
        int left = 1;
        int right = (1 << (height - 1));
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (existsKthNode(root, mid, height)) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return ans + (1 << (height - 1)) - 1;
    }
};