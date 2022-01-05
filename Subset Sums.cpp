class Solution {
public:
    void solve(vector<int> arr, int n, int i, int curr, vector<int> &ans) {
        if (i == n) {
            ans.push_back(curr);
            return;
        }
        
        solve(arr, n, i + 1, curr, ans);
        solve(arr, n, i + 1, curr + arr[i], ans);
    }

    vector<int> subsetSums(vector<int> arr, int N) {
        vector<int> ans;
        sort(arr.begin(), arr.end());
        solve(arr, N, 0, 0, ans);
        return ans;
    }
};
