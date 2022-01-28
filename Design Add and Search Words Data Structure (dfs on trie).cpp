struct trieNode {
    char val;
    bool end;
    vector<trieNode*> child { vector<trieNode*>(26, nullptr) };
};

class WordDictionary {
private:
    trieNode* root;
    
    bool dfs(string word, int i, trieNode* temp) {
        if (!temp) {
            return false;
        }
        
        if (i == word.size()) {
            return temp -> end;
        }
        
        if (word[i] != '.') {
            if (temp -> child[word[i] - 'a']) {
                return dfs(word, i + 1, temp -> child[word[i] - 'a']);
                
            } else {
                return false;
            }
            
        } else {
            for (auto child: temp -> child) {
                if (dfs(word, i + 1, child)) {
                    return true;
                }
            }
            
            return false;
        }
    }
    
public:
    WordDictionary() {
        this -> root = new trieNode;
        this -> root -> val = '*';
        this -> root -> end = false;
    }
    
    bool search(string word) {
        return dfs(word, 0, root);
    }
    
    void addWord(string word) {
        trieNode* temp = root;
        int n = word.size();
        
        for (int i = 0; i < n; i ++) {
            if (temp -> child[word[i] - 'a']) {
                temp = temp -> child[word[i] - 'a'];
                
            } else {
                temp -> child[word[i] - 'a'] = new trieNode;
                temp -> child[word[i] - 'a'] -> val = word[i];
                temp -> child[word[i] - 'a'] -> end = false;
                temp = temp -> child[word[i] - 'a'];
            }
            
            if (i == word.size() - 1) {
                temp -> end = true;
            }
        }
    }
};
