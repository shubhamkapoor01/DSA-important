class Solution {
public:
    bool canReach(string s, int mi, int mx) {
        int n = s.size();
        queue<int> q;
        q.push(0);
        
        int far = 1;
        while (!q.empty()) {
            int pos = q.front();;
            q.pop();
            
            int start = max(far, pos + mi);
            int end = min(pos + mx, n - 1);
            
            for (int i = start; i <= end; i ++) {
                if (s[i] == '0') {
                    q.push(i);
                    
                    if (i == n - 1) {
                        return true;
                    }
                }
            }
            
            far = end + 1;
        }
        return false;
    }
};

