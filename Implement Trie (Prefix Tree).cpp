struct trieNode {
    char val;
    bool ending;
    vector<trieNode*> next {vector<trieNode*> (26, nullptr)};
};

class Trie {
    trieNode* root;
    
public:
    Trie() {
        this -> root = new trieNode;
        this -> root -> val = ' ';
        this -> root -> ending = false;
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
                
                temp -> next[curr] = child;
                temp = child;
            }
            
            if (i == n - 1) {
                temp -> ending = true;
            }
        }
    }
    
    bool search(string word) {
        int n = word.size();
        trieNode* temp = root;
        
        for (int i = 0; i < n; i ++) {
            int curr = word[i] - 'a';
            
            if (temp -> next[curr]) {
                temp = temp -> next[curr];
            } else {
                return false;
            }
            
            if (i == n - 1 && temp -> ending) {
                return true;
            }
        }
        return false;
    }
    
    bool startsWith(string prefix) {
        int n = prefix.size();
        trieNode* temp = root;
        
        for (int i = 0; i < n; i ++) {
            int curr = prefix[i] - 'a';
            
            if (temp -> next[curr]) {
                temp = temp -> next[curr];
            } else {
                return false;
            }
        }
        return true;
    }
};
