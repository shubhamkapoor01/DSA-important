class Solution {
private:
    bool possible(vector<int>& v, int n, int m) {
        int cnt = 0;
        
        for (int i = 0; i < v.size(); i ++) {
            cnt += (v[i] + ((v[i] % m == 0) ? 0 : m - v[i] % m)) / m;
        }
        
        return cnt <= n;
    }
    
public:
    int minimizedMaximum(int n, vector<int>& v) {
        int r = *max_element(v.begin(), v.end());
        int ans = 0;
        int l = 1;
        
        while (l <= r) {
            int m = l + (r - l) / 2;
            
            if (possible(v, n, m)) {
                r = m - 1;
                ans = m;
                
            } else {
                l = m + 1;
            }
        }
        
        return ans;
    }
};

