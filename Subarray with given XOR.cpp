int Solution::solve(vector<int> &A, int B) {
    int ans = 0;
    int curr = 0;
    int n = A.size();
    unordered_map<int, int> m;
        
    for (int i = 0; i < n; i ++) {
        curr = curr xor A[i];
        
        if (curr == B) {
            ans ++;
        }
        
        if (m.find(curr xor B) != m.end()) {
            ans += m[curr xor B];
        }
        
        m[curr] ++;
    }
    
    return ans;
}
