/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Codec {
private:
    int getNext(string& s, int& i) {
        int val = 0;
        bool neg = s[i] == '-';
        if (neg) {
            i ++;
        }
        
        while (i < s.size() && s[i] != ' ') {
            val = val * 10 + s[i] - '0';
            i ++;
        }
        i ++;
        
        return neg ? -1 * val : val;
    }
    
public:
    // Encodes your tree into a string.
    string serialize(TreeNode* root) {
        if (!root) {
            return "N";
        }
        
        queue<TreeNode*> q;
        q.push(root);
        string data;
        
        while (!q.empty()) {
            TreeNode* curr = q.front();
            data += (curr ? to_string(curr -> val) : "N") + " ";
            q.pop();
            
            if (curr) {
                q.push(curr -> left);
                q.push(curr -> right);
            }
        }
        
        data.pop_back();
        return data;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "N") {
            return nullptr;
        }
        
        int idx = 0;
        int rootData = getNext(data, idx);
        TreeNode* root = new TreeNode(rootData);
        queue<TreeNode*> q;
        q.push(root);
        
        while (idx < data.size()) {
            TreeNode* curr = q.front();
            q.pop();
            
            if (data[idx] == 'N') {
                idx += 2;
            } else {
                int leftVal = getNext(data, idx);
                TreeNode* leftChild = new TreeNode(leftVal);
                curr -> left = leftChild;
                q.push(leftChild);
            }
            
            if (idx >= data.size()) {
                break;
            }
            
            if (data[idx] == 'N') {
                idx += 2;
            } else {
                int rightVal = getNext(data, idx);
                TreeNode* rightChild = new TreeNode(rightVal);
                curr -> right = rightChild;
                q.push(rightChild);
            }
        }
        
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));