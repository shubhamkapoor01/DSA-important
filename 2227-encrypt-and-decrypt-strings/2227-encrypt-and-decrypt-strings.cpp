class Encrypter {
private:
    unordered_map<char, string> e;
    unordered_map<string, vector<char>> d;
    unordered_set<string> dict;
    
public:
    Encrypter(vector<char>& keys, vector<string>& values, vector<string>& dictionary) {
        int n = keys.size();
        for (int i = 0; i < n; i ++) {
            e[keys[i]] = values[i];
            d[values[i]].push_back(keys[i]);
        }
        
        int m = dictionary.size();
        for (int i = 0; i < m; i ++) {
            dict.insert(dictionary[i]);
        }
    }
    
    string encrypt(string word) {
        int n = word.size();
        string ciphertext;
        for (int i = 0; i < n; i ++) {
            if (e.find(word[i]) == e.end()) {
                ciphertext += '#';
            } else {
                ciphertext += e[word[i]];
            }
        }
        return ciphertext;
    }
    
    int decrypt(string word) {
        int cnt = 0;
        for (auto i: dict) {
            if (encrypt(i) == word) {
                // cout << i << endl;
                cnt ++;
            }
        }
        return cnt;
    }
};

/**
 * Your Encrypter object will be instantiated and called as such:
 * Encrypter* obj = new Encrypter(keys, values, dictionary);
 * string param_1 = obj->encrypt(word1);
 * int param_2 = obj->decrypt(word2);
 */