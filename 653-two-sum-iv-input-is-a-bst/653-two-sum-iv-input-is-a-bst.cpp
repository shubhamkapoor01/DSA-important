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
    int val;
    
public:
    BSTIterator(TreeNode* root) {
        curr = root;
        next();
    }
    
    void next() {
        while (curr) {
            st.push_back(curr);
            curr = curr -> left;
        }
        
        if (!st.size()) {
            val = -1e9;
            return;
        }
        
        curr = st.back();
        val = curr -> val;
        curr = curr -> right;
        st.pop_back();
    }
    
    int getVal() {
        return val;
    }
};

class BSTReverseIterator {
    vector<TreeNode*> st;
    TreeNode* curr;
    int val;
    
public:
    BSTReverseIterator(TreeNode* root) {
        curr = root;
        next();
    }
    
    void next() {
        while (curr) {
            st.push_back(curr);
            curr = curr -> right;
        }
        
        if (!st.size()) {
            val = -1e9;
            return;
        }
        
        curr = st.back();
        val = curr -> val;
        curr = curr -> left;
        st.pop_back();
    }
    
    int getVal() {
        return val;
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        BSTIterator it(root);
        BSTReverseIterator rit(root);
        
        while (it.getVal() != rit.getVal()) {
            if (it.getVal() + rit.getVal() == k) {
                return true;
            }
            
            if (it.getVal() + rit.getVal() > k) {
                rit.next();
            } else {
                it.next();
            }
        }
        
        return false;
    }
};