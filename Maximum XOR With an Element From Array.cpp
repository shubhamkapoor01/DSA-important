struct trieNode {
    int val;
    trieNode* zero = nullptr;
    trieNode* one = nullptr;
};

class Trie {
    trieNode* root;
    
public:
    Trie() {
        this -> root = new trieNode();
        this -> root -> val = 0;
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
                    temp = temp -> one;
                }
                
            } else {
                if (temp -> zero) {
                    temp = temp -> zero;
                    
                } else {
                    temp -> zero = new trieNode;
                    temp -> zero -> val = 0;
                    temp = temp -> zero;
                }
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
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        vector<pair<int, pair<int, int>>> p;
        int n = nums.size();
        int q = queries.size();
        
        for (int i = 0; i < q; i ++) {
            p.push_back({queries[i][1], {queries[i][0], i}});
        }
        
        sort(nums.begin(), nums.end());
        sort(p.begin(), p.end());
        
        Trie root;
        int idx = 0;
        vector<int> ans(p.size());
        
        for (int i = 0; i < q; i ++) {
            while (idx < n && nums[idx] <= p[i].first) {
                root.insert(nums[idx]);
                idx ++;
            }
            
            if (idx == 0) {
                ans[p[i].second.second] = -1;
            } else {
                ans[p[i].second.second] = root.maxXor(p[i].second.first);
            }
        }
        return ans;
    }
};
