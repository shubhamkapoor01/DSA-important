struct trieNode {
    char val;
    bool ending;
    vector<trieNode*> next {vector<trieNode*> (26, nullptr)};
};

class Trie {
    trieNode* root;
    int count;
    
public:
    Trie() {
        this -> count = 0;
        this -> root = new trieNode;
        this -> root -> val = ' ';
        this -> root -> ending = false;
    }
    
    int getCount() {
        return this -> count;
    }
    
    void insert(string word) {
        int n = word.size();
        trieNode* temp = root;
        
        for (int i = 0; i < n; i ++) {
            int curr = word[i] - 'a';
            
            if (temp -> next[curr]) {
                temp = temp -> next[curr];
                
            } else {
                trieNode* child = new trieNode;
                child -> val = word[i];
                child -> ending = false;
                
                this -> count ++;
                temp -> next[curr] = child;
                temp = child;
            }
            
            if (i == n - 1) {
                temp -> ending = true;
            }
        }
    }
};

int countDistinctSubstrings(string &s) {
    int n = s.size();
    Trie root;
    
    for (int i = 0; i < n; i ++) {
        root.insert(s.substr(i));
    }
    
    return root.getCount() + 1;
}
