class Solution {
public:
    int factorial(int n) {
        if (n == 0) {
            return 1;
        }
        return n * factorial(n - 1);
    }
    
    string solve(vector<int> v, int k) {
        if (v.size() == 0) {
            return "";
        } else if (v.size() == 1) {
            return to_string(v[0]);
        }
        
        int fac = factorial(v.size() - 1);
        
        int first = k / fac;
        int element = v[first];
        v.erase(v.begin() + first);
        
        string remaining = solve(v, k % fac);
        return to_string(element) + remaining;
    }
    
    string getPermutation(int n, int k) {
        vector<int> v;
        for (int i = 0; i < n; i ++) {
            v.push_back(i + 1);
        }
        return solve(v, k - 1);
    }
};
