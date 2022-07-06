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

class BSTIterator {
    vector<TreeNode*> st;
    TreeNode* curr;
    
public:
    BSTIterator(TreeNode* root) {
        curr = root;
    }
    
    int next() {
        while (curr) {
            st.push_back(curr);
            curr = curr -> left;
        }
        
        curr = st.back();
        int val = curr -> val;
        curr = curr -> right;
        st.pop_back();
        
        return val;
    }
    
    bool hasNext() {
        return curr || st.size();
    }
};

//   c
// 7 3 <top

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */