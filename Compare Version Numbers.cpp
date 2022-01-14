class Solution {
    bool greater(string a, string b) {
        int n = a.size();
        
        if (a.size() > b.size()) {
            return true;
        }
        if (b.size() > a.size()) {
            return false;
        }
        
        for (int i = 0; i < n; i ++) {
            if (a[i] > b[i]) {
                return true;
            }
        }
        
        return false;
    }
    
public:
    int compareVersion(string one, string two) {
        int n = one.size();
        int m = two.size();
        int i = 0;
        int j = 0;
        
        while (i < n && j < m) {
            while (i < n && one[i] == '0') {
                i ++;
            }
            while (j < m && two[j] == '0') {
                j ++;
            }
            
            string wordone = "";
            string wordtwo = "";
            
            while (i < n && one[i] != '.') {
                wordone.push_back(one[i]);
                i ++;
            }
            
            while (j < m && two[j] != '.') {
                wordtwo.push_back(two[j]);
                j ++;
            }
            
            if (greater(wordone, wordtwo)) {
                return 1;
            } else if (greater(wordtwo, wordone)) {
                return -1;
            } 
            
            i ++;
            j ++;
        }
        
        bool remone = false;
        bool remtwo = false;
        
        while (i < n) {
            if (one[i] != '0' && one[i] != '.') {
                remone = true;
                break;
            }
            i ++;
        }   
        
        while (j < m) {
            if (two[j] != '0' && two[j] != '.') {
                remtwo = true;
                break;
            }
            j ++;
        }
        
        if (remone) {
            return 1;
        } else if (remtwo) {
            return -1;
        }
        
        return 0;
    }
};
