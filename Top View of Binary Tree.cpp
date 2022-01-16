class Solution {
    public:
    vector<int> topView(Node *root) {
        map<int, int> bottom;
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        
        while (!q.empty()) {
            Node* front = q.front().first;
            int level = q.front().second;
            q.pop();
            
            if (bottom.find(level) == bottom.end()) {
                bottom[level] = front -> data;
            }
            
            if (front -> left) {
                q.push({front -> left, level - 1});
            }
            if (front -> right) {
                q.push({front -> right, level + 1});
            }
        }    
    
        vector<int> ans;
        for (auto i: bottom) {
            ans.push_back(i.second);
        }
        return ans;
    }
};
