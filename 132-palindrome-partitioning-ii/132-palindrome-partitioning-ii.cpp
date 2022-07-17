class Solution {
public:
int minCut(string s){
    int n = s.size();
    vector<vector<bool>>isPal(n, vector<bool>(n, false));
    vector<int>dp(n,0);
    for(int i = n-1; i >= 0; i--){
        for(int j = 0; j < n; j++){
            if(i >= j){
                isPal[i][j] = true;
            }else{
                if(s[i] == s[j]){
                    isPal[i][j] = isPal[i+1][j-1];
                }else{
                    isPal[i][j] = false;
                }
            }
        }
    }
    for(int i = 1; i < n ; i++){
        if(isPal[0][i]){
            dp[i] = 0;
            continue;
        }
        int minimum = INT_MAX;
        for(int j = i; j >= 1; j--){
            if(isPal[j][i]){
                minimum = min(minimum, dp[j-1]);
            }
        }
        dp[i] = minimum + 1;
    }
    return dp[n-1];
}
};