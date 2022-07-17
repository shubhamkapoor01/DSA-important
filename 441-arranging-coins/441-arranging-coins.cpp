class Solution {
public:
    int arrangeCoins(long n) {
        return (1 + sqrt(1 + 8 * n)) / 2 - 1;
    }
};


// m*(m+1) = 2*n;
// m^2 + m = 2*n;
// m^2 + m - 2*n = 0;
// m = (1 + sqrt(1 + 8 * n)) / 2;
