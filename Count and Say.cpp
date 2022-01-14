class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) {
            return "1";
        }
        
        string prev = countAndSay(n - 1);
        string curr = "";
        
        for (int i = 0; i < prev.size(); i ++) {
            char current = prev[i];
            int count = 0;
            int j = i;
            
            while (prev[j] == prev[i]) {
                count ++;
                j ++;
            }
            
            curr = curr + to_string(count);
            curr.push_back(current);
            i = j - 1;
        }
        
        // cout << n << " " << curr << endl;
        return curr;
    }
};
