class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        
        string prev = countAndSay(n - 1);
        string curr = "";
        
        for (int i = 0; i < prev.size();) {
            char ch = prev[i];
            int cnt = 0;
            int j = i;
            
            while (j < prev.size() && prev[i] == prev[j]) {
                cnt ++;
                j ++;
            }
            
            curr += to_string(cnt);
            curr += prev[i];
            i = j;
        }
        
        return curr;
    }
};