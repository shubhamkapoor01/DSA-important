// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution {
    private:
        int solve(string& s, int i, int j, vector<vector<int>>& dp) {
            if (i == s.size() || j == s.size()) {
                return 0;
            }
            
            if (dp[i][j] != -1) {
                return dp[i][j];
            }
            
            if (s[i] == s[j] && i != j) {
                dp[i][j] = 1 + solve(s, i + 1, j + 1, dp);
                
            } else {
                dp[i][j] = max(solve(s, i + 1, j, dp), solve(s, i, j + 1, dp));
            }
            
            return dp[i][j];
        }
    
	public:
		int LongestRepeatingSubsequence(string& s) {
		    int n = s.size();
		    vector<vector<int>> dp(n, vector<int> (n, -1));
		    return solve(s, 0, 0, dp);
		}
};


// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends