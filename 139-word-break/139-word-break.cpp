class Solution {
public:
//     bool wordBreak(string s, vector<string>& words) {
//         int n = s.size();
//         vector<bool> dp(n + 1, false);
//         dp[0] = true;
        
//         for (int i = 1; i <= n; i ++) {
//             for (auto &word: words) {
//                 if (i >= word.size() && word == s.substr(i - word.size(), word.size())) {
//                     dp[i] = dp[i] || dp[i - word.size()];
//                 }
//             }
//         }
        
//         return dp[n];
//     }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> set;
        int n = s.size();
        vector<int> dp(n+1,0);
        for(auto it : wordDict){
            set.insert(it);
        }
        dp[n] = true;
        for(int i = n-1; i>=0; i--){
            string inter;
            for(int j = i;j<n;j++){
               inter+=s[j];
               if(set.find(inter)!=set.end()){
                   if(dp[j+1]) dp[i] = true;
               }
            }
        }
       return dp[0]; 
    }
};


