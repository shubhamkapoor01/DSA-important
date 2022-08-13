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
private:
    unordered_map<long, long> prefix;
    
    void solve(TreeNode* root, long& sum, int& target, int& cnt) {
        if (!root) {
            return;
        }
        
        sum += root -> val;
        cnt += prefix[sum - target];
        prefix[sum] ++;
        
        solve(root -> left, sum, target, cnt);
        solve(root -> right, sum, target, cnt);
        
        prefix[sum] --;
        sum -= root -> val;
        return;
    }
    
public:
    int pathSum(TreeNode* root, int target) {
        prefix[0] = 1;
        long sum = 0;
        int cnt = 0;
        solve(root, sum, target, cnt);
        return cnt;
    }
};