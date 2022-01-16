class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, long>> q;
        q.push({root, 0});
        
        long maxWidth = 0;
        while (!q.empty()) {
            long n = q.size();
            long start = 0;
            long end = 0;
            
            while (n --) {         
                TreeNode* node = q.front().first;
                long index = q.front().second;
                q.pop();
                
                if (!start) {
                    start = index;
                }
                end = index;
                
                index = index - start;

                if (node -> left) {
                    q.push({node -> left, 2 * index + 1});
                }
                if (node -> right) {
                    q.push({node -> right, 2 * index + 2});
                }
            }
            maxWidth = max(maxWidth, end - start + 1);
        }
        return maxWidth;
    }
};
