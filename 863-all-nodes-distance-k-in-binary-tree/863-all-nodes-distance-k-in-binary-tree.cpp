/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
private:
    void dfs(unordered_map<TreeNode*, vector<TreeNode*>>& graph, TreeNode* root) {
        if (root -> left) {
            graph[root].push_back(root -> left);
            graph[root -> left].push_back(root);
            dfs(graph, root -> left);
        }
        if (root -> right) {
            graph[root].push_back(root -> right);
            graph[root -> right].push_back(root);
            dfs(graph, root -> right);
        }
    }
    
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if (!k) return {target -> val};
        unordered_map<TreeNode*, vector<TreeNode*>> graph;
        dfs(graph, root);
        // for (auto node: graph) {
        //     cout << node.first -> val << ": ";
        //     for (auto neighbour: node.second) {
        //         cout << neighbour -> val << " ";
        //     }
        //     cout << endl;
        // }  
        // cout << endl;
        vector<int> v;
        unordered_set<TreeNode*> vis;
        queue<pair<TreeNode*, int>> q;
        q.push({target, 0});
        vis.insert(target);
        while (q.size()) {
            TreeNode* root = q.front().first;
            int dist = q.front().second;
            if (dist == k) v.push_back(root -> val);
            if (dist > k) break;
            for (auto child: graph[root]) {
                if (vis.find(child) == vis.end()) {
                    q.push({child, dist + 1});
                    vis.insert(child);
                }
            }
            q.pop();
        }
        return v;
    }
};