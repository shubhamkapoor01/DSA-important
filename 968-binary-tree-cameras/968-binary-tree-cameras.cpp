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
    static const int looked_by_cam = 2;
    static const int need_cam = 1;
    static const int has_cam = 0;
    
    int camera;
public:
    
    int find(TreeNode* node){
        if (!node) return looked_by_cam;
        
        int left = find(node->left);
        int right = find(node->right);
        
        if (left == need_cam || right == need_cam){
            camera ++;
            return has_cam;
        }
        
        if (left == has_cam || right == has_cam){
            return looked_by_cam;
        }
        
        return need_cam;
    }
    
    int minCameraCover(TreeNode* root) {
        camera = 0;
        
        int rootStatus = find(root);
        if (rootStatus == need_cam) camera++;
        
        return camera;
    }
};