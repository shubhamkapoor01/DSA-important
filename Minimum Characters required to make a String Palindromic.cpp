vector<int> generateLPS(string s) {
    int n = s.size();
    vector<int> lps(n, 0);
    int j = 0;
    
    for (int i = 1; i < n;) {
        if (s[i] == s[j]) {
            lps[i] = j + 1;
            i ++;
            j ++;
        
        } else {
            if (j == 0) {
                lps[i] = 0;
                i ++;
            
            } else {
                j = lps[j - 1];
            }
        }
    }
    
    return lps;
}

int Solution::solve(string s) {
    int n = s.size();
    
    string t = s;
    reverse(t.begin(), t.end());
    
    if (t == s) {
        return 0;
    }
    s = s + t;
    
    vector<int> lps = generateLPS(s);
    return t.size() - lps[2 * n - 1];
}
