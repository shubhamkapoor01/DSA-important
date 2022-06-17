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
    const int lookedByCam = 0;
    const int needsCam = 1;
    const int hasCam = 2;
    
    int solve(TreeNode* root, int& cameras) {
        if (!root) {
            return lookedByCam;
        }
        
        if (!root -> left && !root -> right) {
            return needsCam;
        }
        
        int left = solve(root -> left, cameras);
        int right = solve(root -> right, cameras);
        
        if (left == needsCam || right == needsCam) {
            cameras ++;
            return hasCam;
        }
        
        if (left == hasCam || right == hasCam) {
            return lookedByCam;
        }
        
        return needsCam;
    }
    
public:
    int minCameraCover(TreeNode* root) {
        int cameras = 0;
        int rootStatus = solve(root, cameras);
        if (rootStatus == needsCam) cameras ++;
        return cameras;
    }
};