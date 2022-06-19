class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        unordered_map<string, vector<string>> mp;
        for (int i = 0; i < products.size(); i ++) {
            string curr = "";
            for (int j = 0; j < products[i].size(); j ++) {
                curr.push_back(products[i][j]);
                mp[curr].push_back(products[i]);
            }
        }
        for (auto &i: mp) {
            sort(i.second.begin(), i.second.end());
        }
        vector<vector<string>> ans;
        string word = "";
        for (int i = 0; i < searchWord.size(); i ++) {
            word.push_back(searchWord[i]);
            vector<string> curr;
            for (int j = 0; j < 3 && j < mp[word].size(); j ++) {
                curr.push_back(mp[word][j]);
            }
            ans.push_back(curr);
        }
        return ans;
    }
};