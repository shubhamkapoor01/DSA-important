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
    bool fillpath(TreeNode* root, int dest, string& path) {
        if (!root) return false;
        if (root -> val == dest) return true;
        
        if (fillpath(root -> left, dest, path)) {
            path.push_back('L');
            return true;
            
        } else if (fillpath(root -> right, dest, path)) {
            path.push_back('R');
            return true;
            
        } else {
            return false;
        }
    }
    
public:
    string getDirections(TreeNode* root, int start, int end) {
        string starttolca;
        string lcatoend;
        
        fillpath(root, start, starttolca);
        fillpath(root, end, lcatoend);
        
        while (starttolca.size() && lcatoend.size() && starttolca.back() == lcatoend.back()) {
            starttolca.pop_back();
            lcatoend.pop_back();
        }
        
        for (auto &i: starttolca) {
            i = 'U';
        }
    
        reverse(lcatoend.begin(), lcatoend.end());
        return starttolca + lcatoend;
    }
};