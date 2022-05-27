class Solution {
private:
    void solve(int size, int n, int i, string& curr, vector<string>& ans) {
        if (i == size) {
            if (n) {
                return;
            }
            ans.push_back(curr);
            return;
        }
        
        curr.push_back('(');
        solve(size, n + 1, i + 1, curr, ans);
        curr.pop_back();
        
        if (n != 0) {
            curr.push_back(')');
            solve(size, n - 1, i + 1, curr, ans);
            curr.pop_back();
        }
    }    
    
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string curr;
        solve(2 * n, 0, 0, curr, ans);
        return ans;
    }
};