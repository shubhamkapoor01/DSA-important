class Solution {
public:
    int kInversePairs(int elements, int inverse) {
        vector<int> curr(inverse + 1, 0);
        vector<int> prev(inverse + 1, 0);
        
        prev[0] = 1;
        curr[0] = 1;
        
        for (int i = 1; i <= elements; i ++) {
            for (int j = 1; j <= inverse; j ++) {
                curr[j] = (prev[j] + curr[j - 1]) % 1000000007;
                if (j >= i) {
                    curr[j] = (curr[j] - prev[j - i] + 1000000007) % 1000000007;
                }
            }
            prev = curr;
        }
        
        return curr[inverse];
    }
};