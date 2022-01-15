struct trieNode {
    int val;
    bool ending;
    trieNode* zero = nullptr;
    trieNode* one = nullptr;
};

class Trie {
    trieNode* root;
    
public:
    Trie() {
        this -> root = new trieNode();
        this -> root -> val = 0;
        this -> root -> ending = false;
    }
    
    void insert(int n) {
        trieNode* temp = root;
        
        for (int i = 31; i >= 0; i --) {
            if (n & (1 << i)) {
                if (temp -> one) {
                    temp = temp -> one;
                    
                } else {
                    temp -> one = new trieNode;
                    temp -> one -> val = 1;
                    temp -> one -> ending = false;
                    temp = temp -> one;
                }
                
            } else {
                if (temp -> zero) {
                    temp = temp -> zero;
                    
                } else {
                    temp -> zero = new trieNode;
                    temp -> zero -> val = 0;
                    temp -> zero -> ending = false;
                    temp = temp -> zero;
                }
            }
            
            if (i == 0) {
                temp -> ending = true;
            }
        }
    }
    
    int maxXor(int num) {
        trieNode* temp = root;
        int complement = 0;
        
        for (int i = 31; i >= 0; i --) {
            if (num & (1 << i)) {
                if (temp -> zero) {
                    temp = temp -> zero;
                    complement = complement * 2;
                    
                } else {
                    temp = temp -> one;
                    complement = complement * 2 + 1;
                }
                    
            } else {
                if (temp -> one) {
                    temp = temp -> one;
                    complement = complement * 2 + 1;
                    
                } else {
                    temp = temp -> zero;
                    complement = complement * 2;
                }
            }
        }
        
        return num xor complement;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int n = nums.size();
        Trie root;
        
        for (int i = 0; i < n; i ++) {
            root.insert(nums[i]);
        }
        
        int result = 0;
        
        for (int i = 0; i < n; i ++) {
            result = max(result, root.maxXor(nums[i]));
        }
        
        return result;
    }
};
