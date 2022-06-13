class Solution {
private:
    long getZerosInFactorial(long num) {
        long curr = 5;
        long ans = 0;
        while (curr <= num) {
            ans += num / curr;
            curr *= 5;
        }
        return ans;
    }
    
    long getFirstWithKZeros(long k) {
        long r = LONG_MAX;
        long l = 0;
        while (l <= r) {
            long m = l + (r - l) / 2;
            if (getZerosInFactorial(m) >= k) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return l;
    }
    
    long getLastWithKZeros(long k) {
        long r = LONG_MAX;
        long l = 0;
        while (l <= r) {
            long m = l + (r - l) / 2;
            if (getZerosInFactorial(m) <= k) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return l - 1;
    }
    
    
public:
    int preimageSizeFZF(int k) {
        long first = getFirstWithKZeros(k);
        long last = getLastWithKZeros(k);
        return last - first + 1;
    }
};
