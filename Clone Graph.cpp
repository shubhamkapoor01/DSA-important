class Solution {
private:
    unordered_map<Node*, Node*> oldToNew;
    
public:
    Node* cloneGraph(Node* node) {
        if (!node) {
            return nullptr;
        }
        
        if (oldToNew.find(node) != oldToNew.end()) {
            return oldToNew[node];
        }
                
        oldToNew[node] = new Node(node -> val);
        vector<Node*> newNeighbors;
        
        for (auto i: node -> neighbors) {
            newNeighbors.push_back(cloneGraph(i));
        }

        oldToNew[node] -> neighbors = newNeighbors;
        return oldToNew[node];
    }
};
