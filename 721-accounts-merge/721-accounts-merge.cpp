class DSU {
private:
    unordered_map<int, int> parent;
    unordered_map<int, int> rank;
    
public:
    DSU (int sz) {
        for (int i = 0; i < sz; i ++) {
            parent[i] = i;
            rank[i] = 1;
        }
    }
    
    int findParent(int x) {
        if (x == parent[x]) {
            return x;
        }
        return parent[x] = findParent(parent[x]);
    }
    
    void unionByRank(int a, int b) {
        int A = findParent(a);
        int B = findParent(b);
        
        if (A == B) {
            return;
        }
        
        if (rank[A] < rank[B]) {
            swap(A, B);
        }
        
        parent[B] = A;
        
        if (rank[A] == rank[B]) {
            rank[A] ++;
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accountList) {
        int accountListSize = accountList.size();
        unordered_map<string, int> emailGroup;
        DSU dsu(accountListSize);
        
        for (int i = 0; i < accountListSize; i++) {
            int accountSize = accountList[i].size();

            for (int j = 1; j < accountSize; j++) {
                string email = accountList[i][j];
                string accountName = accountList[i][0];
                
                if (emailGroup.find(email) == emailGroup.end()) {
                    emailGroup[email] = i;
                } else {
                    dsu.unionByRank(i, emailGroup[email]);
                }
            }
        }
    
        unordered_map<int, vector<string>> components;
        for (auto emailIterator : emailGroup) {
            string email = emailIterator.first;
            int group = emailIterator.second;
            components[dsu.findParent(group)].push_back(email);
        }

        vector<vector<string>> mergedAccounts;
        for (auto componentIterator : components) {
            int group = componentIterator.first;
            vector<string> component = {accountList[group][0]};
            component.insert(component.end(), componentIterator.second.begin(), 
                             componentIterator.second.end());
            sort(component.begin() + 1, component.end());
            mergedAccounts.push_back(component);
        }
        
        return mergedAccounts;
    }
};